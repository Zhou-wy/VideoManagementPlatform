//
// Created by zhouwy on 2023/2/21.
//

#include "Json.h"

#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QJsonParseError>

/*-----------------------------------------------------------------------------|
 |                         JsonPrivate implementation                          |
 |----------------------------------------------------------------------------*/
struct JsonPrivate {
    JsonPrivate(const QString &jsonOrJsonFilePath, bool fromFile);

    void remove(QJsonObject &parent, const QString &path); // ɾ�� path ��Ӧ������
    void setValue(QJsonObject &parent, const QString &path, const QJsonValue &newValue); // ���� path ��ֵ
    QJsonValue getValue(const QString &path, const QJsonObject &fromNode) const; // ��ȡ path ��ֵ

    QJsonObject root;    // Json �ĸ��ڵ�
    QJsonDocument doc;   // Json ���ĵ�����
    bool valid = true;   // Json �Ƿ���Ч
    QString errorString; // Json ��Чʱ�Ĵ�����Ϣ
};

JsonPrivate::JsonPrivate(const QString &jsonOrJsonFilePath, bool fromFile) {
    QByteArray json("{}"); // json ������

    // ������˵��� Json �ļ���·�������ȡ����
    if (fromFile) {
        QFile file(jsonOrJsonFilePath);

        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            json = file.readAll();
        } else {
            valid = false;
            errorString = QString("Cannot open the file: %1").arg(jsonOrJsonFilePath);
//            INFOE(errorString.toStdString().c_str());
            return;
        }
        file.close();
    } else {
        json = jsonOrJsonFilePath.toUtf8();
    }

    // ���� Json
    QJsonParseError error;
    doc = QJsonDocument::fromJson(json, &error);

    if (QJsonParseError::NoError == error.error) {
        root = doc.object();
    } else {
        valid = false;
        errorString = QString("%1\nOffset: %2").arg(error.errorString()).arg(error.offset);
        qDebug() << errorString;
    }
}

// ɾ�� path ��Ӧ������
void JsonPrivate::remove(QJsonObject &parent, const QString &path) {
    const int indexOfDot   = path.indexOf('.');     // ��һ�� . ��λ��
    const QString property = path.left(indexOfDot); // ��һ�� . ֮ǰ�����ݣ���� indexOfDot �� -1 �򷵻������ַ���
    const QString restPath = (indexOfDot>0) ? path.mid(indexOfDot+1) : QString(); // ��һ�� . ���������

    if(restPath.isEmpty()) {
        // restPath Ϊ��, ˵�� property ���� path �����һ�� . �ұߵĲ���, Ҳ����Ҫɾ��������
        parent.remove(property);
    } else {
        // ·���м�����ԣ��ݹ��������������
        QJsonObject child = parent[property].toObject();
        remove(child, restPath);
        parent[property] = child;
    }
}

// ʹ�õݹ�+�������� Json ��ֵ����Ϊ toObject() �ȷ��ص��Ƕ���ĸ����������޸Ĳ���ı�ԭ���Ķ���������Ҫ��������ʵ��
void JsonPrivate::setValue(QJsonObject &parent, const QString &path, const QJsonValue &newValue) {
    const int indexOfDot   = path.indexOf('.');     // ��һ�� . ��λ��
    const QString property = path.left(indexOfDot); // ��һ�� . ֮ǰ�����ݣ���� indexOfDot �� -1 �򷵻������ַ���
    const QString restPath = (indexOfDot>0) ? path.mid(indexOfDot+1) : QString(); // ��һ�� . ���������

    QJsonValue fieldValue = parent[property];

    if(restPath.isEmpty()) {
        // restPath Ϊ��, ˵�� property ���� path �����һ�� . �ұߵĲ���, Ҳ����Ҫ���õ�����
        parent[property] = newValue; // �����������ᴴ��
    } else {
        // ·���м�����ԣ��ݹ��������������
        QJsonObject child = parent[property].toObject();
        setValue(child, restPath, newValue);
        parent[property] = child; // ��Ϊ QJsonObject �����Ķ��Ƕ���ĸ��������Եݹ��������Ҫ���������ٴ����û� parent
    }
}

// ��ȡ���Ե�ֵ����� fromNode Ϊ�գ���Ӹ��ڵ㿪ʼ����
QJsonValue JsonPrivate::getValue(const QString &path, const QJsonObject &fromNode) const {
    // 1. ȷ�������ĸ��ڵ㣬��� fromNode Ϊ���������ĸ��ڵ�Ϊ root
    // 2. �� path ʹ�÷ָ��� . �ֽ�ɶ����������
    // 3. �������ĸ��ڵ㿪ʼ���²��ҵ������ڶ����������ֶ�Ӧ�� QJsonObject parent
    //    �� "user.address.street"��Ҫ���õ�����Ϊ street������ parent �� address
    // 4. ���� parent ��������Ϊ������һ���������ֶ�Ӧ������ֵ

    // [1] ȷ�������ĸ��ڵ㣬��� fromNode Ϊ���������ĸ��ڵ�Ϊ root
    // [2] �� path ʹ�÷ָ��� . �ֽ�ɶ����������
    QJsonObject parent = fromNode.isEmpty() ? root : fromNode;
    QStringList names  = path.split(QRegularExpression("\\."));

    // [3] �������ĸ��ڵ㿪ʼ���²��ҵ������ڶ����������ֶ�Ӧ�� QJsonObject parent
    int size = names.size();
    for (int i = 0; i < size - 1; ++i) {
        if (parent.isEmpty()) {
            return QJsonValue();
        }

        parent = parent.value(names.at(i)).toObject();
    }

    // [4] ���� parent ��������Ϊ������һ���������ֶ�Ӧ������ֵ
    return parent.value(names.last());
}

/*-----------------------------------------------------------------------------|
 |                             Json implementation                             |
 |----------------------------------------------------------------------------*/
Json::Json(const QString &jsonOrJsonFilePath, bool fromFile) : d(new JsonPrivate(jsonOrJsonFilePath, fromFile)) {
}

Json::~Json() {
    delete d;
}

// JSON �Ƿ���Ч����Ч�� JSON ���� true�����򷵻� false
bool Json::isValid() const {
    return d->valid;
}

// JSON ��Чʱ�Ĵ�����Ϣ
QString Json::errorString() const {
    return d->errorString;
}

int Json::getInt(const QString &path, int def, const QJsonObject &fromNode) const {
    return getJsonValue(path, fromNode).toInt(def);
}

bool Json::getBool(const QString &path, bool def, const QJsonObject &fromNode) const {
    return getJsonValue(path, fromNode).toBool(def);
}

double Json::getDouble(const QString &path, double def, const QJsonObject &fromNode) const {
    return getJsonValue(path, fromNode).toDouble(def);
}

QString Json::getString(const QString &path, const QString &def, const QJsonObject &fromNode) const {
    return getJsonValue(path, fromNode).toString(def);
}

QStringList Json::getStringList(const QString &path, const QJsonObject &fromNode) const {
    QStringList result;
    QJsonArray array = getJsonValue(path, fromNode).toArray();

    for (QJsonArray::const_iterator iter = array.begin(); iter != array.end(); ++iter) {
        QJsonValue value = *iter;
        result << value.toString();
    }

    return result;
}

QJsonArray Json::getJsonArray(const QString &path, const QJsonObject &fromNode) const {
    // ������ڵ�������ʱ���⴦��
    if (("." == path || "" == path) && fromNode.isEmpty()) {
        return d->doc.array();
    }

    return getJsonValue(path, fromNode).toArray();
}

QJsonObject Json::getJsonObject(const QString &path, const QJsonObject &fromNode) const {
    return getJsonValue(path, fromNode).toObject();
}

QJsonValue Json::getJsonValue(const QString &path, const QJsonObject &fromNode) const {
    return d->getValue(path, fromNode);
}


void Json::set(const QString &path, const QJsonValue &value) {
    d->setValue(d->root, path, value);
}

void Json::set(const QString &path, const QStringList &strings) {
    QJsonArray array;

    for (const QString &str : strings) {
        array.append(str);
    }

    d->setValue(d->root, path, array);
}

// ɾ�� path ��Ӧ������
void Json::remove(const QString &path) {
    d->remove(d->root, path);
}

// �� JSON ���浽 path ָ�����ļ�
void Json::save(const QString &path, bool pretty) const {
    QFile file(path);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        return;
    }

    QTextStream out(&file);
    out << toString(pretty);
    out.flush();
    file.close();
}

// �� Json ����ת��Ϊ JSON �ַ���
QString Json::toString(bool pretty) const {
    return QJsonDocument(d->root).toJson(pretty ? QJsonDocument::Indented : QJsonDocument::Compact);
}
