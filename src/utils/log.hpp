/*
 * @description:
 * @version:
 * @Author: zwy
 * @Date: 2022-10-16 16:16:26
 * @LastEditors: zwy
 * @LastEditTime: 2022-11-03 16:22:13
 */
#ifndef __HTTP_SERVER_LOG_HPP
#define __HTTP_SERVER_LOG_HPP

#include <string>
#include <memory>
#include <list>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdint.h>
#include <stdarg.h>
#include <map>

#include "singleton.hpp"
#include "utils.hpp"

// 使用流式方式将日志级别level的日志写入到logger
#define LOGGER_LOG_LEVEL(logger, level)                                                                                             \
    if (logger->getLevel() <= level)                                                                                                \
    zwy::LogEventWrap(zwy::LogEvent::ptr(new zwy::LogEvent(logger, level,                                                           \
                                                           __FILE__, __LINE__, 0, zwy::GetThreadId(), zwy::GetFiberId(), time(0)))) \
        .getSS()

#define LOGGER_DEBUG(logger) LOGGER_LOG_LEVEL(logger, zwy::LogLevel::DEBUG)
#define LOGGER_INFO(logger) LOGGER_LOG_LEVEL(logger, zwy::LogLevel::INFO)
#define LOGGER_WARN(logger) LOGGER_LOG_LEVEL(logger, zwy::LogLevel::WARN)
#define LOGGER_ERROR(logger) LOGGER_LOG_LEVEL(logger, zwy::LogLevel::ERROR)
#define LOGGER_FATAL(logger) LOGGER_LOG_LEVEL(logger, zwy::LogLevel::FATAL)

// 用格式化方式将日志级别level的日志写入到logger
#define LOGGER_FMT_LOG_LEVEL(logger, level, fmt, ...)                                                                               \
    if (logger->getLevel() <= level)                                                                                                \
    zwy::LogEventWrap(zwy::LogEvent::ptr(new zwy::LogEvent(logger, level,                                                           \
                                                           __FILE__, __LINE__, 0, zwy::GetThreadId(), zwy::GetFiberId(), time(0)))) \
        .getEvent()                                                                                                                 \
        ->format(fmt, ##__VA_ARGS__)

#define LOGGER_FMT_DEBUG(logger, fmt, ...) LOGGER_FMT_LOG_LEVEL(logger, zwy::LogLevel::DEBUG, fmt, ##__VA_ARGS__)
#define LOGGER_FMT_INFO(logger, fmt, ...) LOGGER_FMT_LOG_LEVEL(logger, zwy::LogLevel::INFO, fmt, ##__VA_ARGS__)
#define LOGGER_FMT_WARN(logger, fmt, ...) LOGGER_FMT_LOG_LEVEL(logger, zwy::LogLevel::WARN, fmt, ##__VA_ARGS__)
#define LOGGER_FMT_ERROR(logger, fmt, ...) LOGGER_FMT_LOG_LEVEL(logger, zwy::LogLevel::ERROR, fmt, ##__VA_ARGS__)
#define LOGGER_FMT_FATAL(logger, fmt, ...) LOGGER_FMT_LOG_LEVEL(logger, zwy::LogLevel::FATAL, fmt, ##__VA_ARGS__)

#define ZLOGGER_ROOT() zwy::LoggerMgr::GetInstance()->getRoot()
#define ZLOGGER_LOG_NAME(name) zwy::LoggerMgr::GetInstance()->getLogger(name)

namespace zwy
{
    class Logger;
    class LoggerManager;
    //日志级别
    class LogLevel
    {
    public:
        enum Level
        {
            UNKOWN = 0,
            DEBUG = 1,
            INFO = 2,
            WARN = 3,
            ERROR = 4,
            FATAL = 5
        };

        static const char *ToString(LogLevel::Level val);
        static LogLevel::Level FromString(const std::string &str);
    };

    //日志事件
    class LogEvent
    {
    public:
        LogEvent(const char *file, uint32_t line, uint32_t elapse, uint32_t thread_id, uint32_t fiber_id,
                 uint64_t time);

        LogEvent(std::shared_ptr<Logger> logger, LogLevel::Level level, const char *file, int32_t line, uint32_t elapse,
                 uint32_t thread_id, uint32_t fiber_id, uint64_t time);

        typedef std::shared_ptr<LogEvent> ptr;

        const char *getFileName() { return m_filename; }

        int32_t getLine() { return m_line; }

        uint32_t getElapse() { return m_elapse; }

        int32_t getThreadId() { return m_threadId; }

        int32_t getFiberId() { return m_fiberId; }

        uint64_t getTime() { return m_time; }

        const std::string &getThreadName() const { return m_threadName; }

        std::string getContext() { return m_ss.str(); }

        std::shared_ptr<Logger> getLogger() const { return m_logger; }

        LogLevel::Level getLevel() const { return m_level; }

        std::stringstream &getSS() { return m_ss; }

        void format(const char *fmt, ...);

        void format(const char *fmt, va_list al);

    private:
        const char *m_filename = nullptr; //文件名
        int32_t m_line = 0;               //行号
        uint32_t m_elapse = 0;            //程序启动到现在的毫秒数
        int32_t m_threadId = 0;           //线程ID
        int32_t m_fiberId = 0;            //协程ID
        uint64_t m_time = 0;              //时间戳
        std::string m_threadName;         //线程名
        std::stringstream m_ss;           //日志内容流
        std::shared_ptr<Logger> m_logger; //日志器
        LogLevel::Level m_level;          //日志等级
    };

    class LogEventWrap
    {
    public:
        LogEventWrap(LogEvent::ptr e);

        ~LogEventWrap();

        LogEvent::ptr getEvent() const { return m_event; }

        std::stringstream &getSS();

    private:
        LogEvent::ptr m_event;
    };

    //日志格式器
    class LogFormatter
    {
    public:
        typedef std::shared_ptr<LogFormatter> ptr;

        std::string format(std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event);

        LogFormatter(const std::string &pattern);

        void init();

        bool isError() const { return m_error; };

        const std::string getPattern() const { return m_pattern; }

    public: //输出格式化父类
        class FormatItem
        {
        public:
            typedef std::shared_ptr<FormatItem> ptr;

            virtual ~FormatItem() {}

            virtual void format(std::ostream &os, std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) = 0;
        };

    private: //输出格式化子类
        std::string m_pattern;
        std::vector<FormatItem::ptr> m_items;
        bool m_error = false;
    };

    //日志输出地
    class LogAppender
    {
        friend class Logger;
    public:
        typedef std::shared_ptr<LogAppender> ptr;

        virtual void log(std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) = 0;

        virtual ~LogAppender(){};

        void setFarmatter(LogFormatter::ptr val);

        LogFormatter::ptr getFarmatter() const
        {
            return m_formatter;
        }

        LogLevel::Level getLevel() const { return m_level; }

        void setLevel(LogLevel::Level val) { m_level = val; }

        virtual std::string toYamlString() = 0;

    protected:
        LogFormatter::ptr m_formatter;
        bool m_hasFormatter = false;
        LogLevel::Level m_level = LogLevel::DEBUG;
    };

    //日志器
    class Logger : public std::enable_shared_from_this<Logger>
    {
        friend class LoggerManager;

    public:
        typedef std::shared_ptr<Logger> ptr;

        Logger(const std::string &name = "root");

        void log(LogLevel::Level level, LogEvent::ptr event);

        void debug(LogEvent::ptr event);

        void info(LogEvent::ptr event);

        void warn(LogEvent::ptr event);

        void error(LogEvent::ptr event);

        void fatal(LogEvent::ptr event);

        void addAppender(LogAppender::ptr appender);

        void delAppender(LogAppender::ptr appender);

        LogLevel::Level getLevel() { return m_level; }

        void setLogLevel(LogLevel::Level val) { m_level = val; }

        const std::string &getName() const { return m_name; }

        void clearAppenders() { m_appender.clear(); }

        void setFormatter(LogFormatter::ptr val);

        void setFormatter(const std::string &val);

        LogFormatter::ptr getFormatter();

        void setLevel(LogLevel::Level val) { m_level = val; }

        std::string toYamlString();

    private:
        std::string m_name;                     //日志名称
        LogLevel::Level m_level;                //日志级别
        std::list<LogAppender::ptr> m_appender; // Appenders 集合
        LogFormatter::ptr m_formatter;
        Logger::ptr m_root;
    };

    class StdoutLogAppender : public LogAppender
    {
    public:
        typedef std::shared_ptr<StdoutLogAppender> ptr;

        std::string toYamlString() override;

        void log(std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) override;
    };

    class FileLogAppender : public LogAppender
    {
    public:
        typedef std::shared_ptr<FileLogAppender> ptr;

        FileLogAppender(const std::string &filename);

        std::string toYamlString() override;

        void log(std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) override;

        bool reopen();

    private:
        std::string m_filename;
        std::ofstream m_filestream;
    };

    class LoggerManager
    {
    public:
        LoggerManager();
        Logger::ptr getLogger(const std::string &name);
        Logger::ptr getRoot() { return m_root; }
        std::string toYamlString();
        void init();

    private:
        std::map<std::string, Logger::ptr> m_logger;
        Logger::ptr m_root;
    };

    typedef zwy::Singleton<LoggerManager> LoggerMgr;

}
#endif
