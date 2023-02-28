/****************************************************************************
** Meta object code from reading C++ file 'ffmpeg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/playFFmpeg/ffmpeg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ffmpeg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FFmpegThread_t {
    QByteArrayData data[12];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FFmpegThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FFmpegThread_t qt_meta_stringdata_FFmpegThread = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FFmpegThread"
QT_MOC_LITERAL(1, 13, 12), // "receiveImage"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "image"
QT_MOC_LITERAL(4, 33, 6), // "setUrl"
QT_MOC_LITERAL(5, 40, 3), // "url"
QT_MOC_LITERAL(6, 44, 4), // "init"
QT_MOC_LITERAL(7, 49, 4), // "free"
QT_MOC_LITERAL(8, 54, 4), // "play"
QT_MOC_LITERAL(9, 59, 5), // "pause"
QT_MOC_LITERAL(10, 65, 4), // "next"
QT_MOC_LITERAL(11, 70, 4) // "stop"

    },
    "FFmpegThread\0receiveImage\0\0image\0"
    "setUrl\0url\0init\0free\0play\0pause\0next\0"
    "stop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FFmpegThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   57,    2, 0x0a /* Public */,
       6,    0,   60,    2, 0x0a /* Public */,
       7,    0,   61,    2, 0x0a /* Public */,
       8,    0,   62,    2, 0x0a /* Public */,
       9,    0,   63,    2, 0x0a /* Public */,
      10,    0,   64,    2, 0x0a /* Public */,
      11,    0,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FFmpegThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FFmpegThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receiveImage((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 1: _t->setUrl((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: { bool _r = _t->init();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->free(); break;
        case 4: _t->play(); break;
        case 5: _t->pause(); break;
        case 6: _t->next(); break;
        case 7: _t->stop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FFmpegThread::*)(const QImage & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FFmpegThread::receiveImage)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FFmpegThread::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_FFmpegThread.data,
    qt_meta_data_FFmpegThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FFmpegThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FFmpegThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FFmpegThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int FFmpegThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void FFmpegThread::receiveImage(const QImage & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_FFmpegWidget_t {
    QByteArrayData data[11];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FFmpegWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FFmpegWidget_t qt_meta_stringdata_FFmpegWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FFmpegWidget"
QT_MOC_LITERAL(1, 13, 11), // "updateImage"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 5), // "image"
QT_MOC_LITERAL(4, 32, 6), // "setUrl"
QT_MOC_LITERAL(5, 39, 3), // "url"
QT_MOC_LITERAL(6, 43, 4), // "open"
QT_MOC_LITERAL(7, 48, 5), // "pause"
QT_MOC_LITERAL(8, 54, 4), // "next"
QT_MOC_LITERAL(9, 59, 5), // "close"
QT_MOC_LITERAL(10, 65, 5) // "clear"

    },
    "FFmpegWidget\0updateImage\0\0image\0setUrl\0"
    "url\0open\0pause\0next\0close\0clear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FFmpegWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       4,    1,   52,    2, 0x0a /* Public */,
       6,    0,   55,    2, 0x0a /* Public */,
       7,    0,   56,    2, 0x0a /* Public */,
       8,    0,   57,    2, 0x0a /* Public */,
       9,    0,   58,    2, 0x0a /* Public */,
      10,    0,   59,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FFmpegWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FFmpegWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateImage((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 1: _t->setUrl((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->open(); break;
        case 3: _t->pause(); break;
        case 4: _t->next(); break;
        case 5: _t->close(); break;
        case 6: _t->clear(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FFmpegWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_FFmpegWidget.data,
    qt_meta_data_FFmpegWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FFmpegWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FFmpegWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FFmpegWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FFmpegWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
