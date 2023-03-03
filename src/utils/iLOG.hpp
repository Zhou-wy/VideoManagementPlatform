//
// Created by zwy on 2023/3/2.
//

#ifndef VIDEOMANPLAT_ILOG_HPP
#define VIDEOMANPLAT_ILOG_HPP

#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <sstream>
#include <iomanip>
#include <windows.h>
#include <iostream>
#include <chrono>
//格式化输入
#define LOGGER_FMT_LEVEL(logger, level, fmt, ...) \
    if((logger).getLevel() <= level)      SPDLOG_LOGGER_CALL(logger.getLogger(), level, fmt, ##__VA_ARGS__)

#define DEBUG_FMT(logger, fmt, ...) LOGGER_FMT_LEVEL(logger, spdlog::level::level_enum::debug, fmt, ##__VA_ARGS__)
#define INFO_FMT(logger, fmt, ...) LOGGER_FMT_LEVEL(logger,spdlog::level::level_enum::info, fmt, ##__VA_ARGS__)
#define WARN_FMT(logger, fmt, ...) LOGGER_FMT_LEVEL(logger, spdlog::level::level_enum::warn, fmt, ##__VA_ARGS__)
#define ERROR_FMT(logger, fmt, ...) LOGGER_FMT_LEVEL(logger, spdlog::level::level_enum::err, fmt, ##__VA_ARGS__)
#define FATAL_FMT(logger, fmt, ...) LOGGER_FMT_LEVEL(logger, spdlog::level::level_enum::critical, fmt, ##__VA_ARGS__)

//流输入
#define LOGGER_STREAM_LEVEL(logger, level) \
if(logger.getLevel() <= spdlog::level::level_enum::debug) \
    logger.getLogger() << __FILE__ << ":" << __LINE__ << " " << __FUNCTION__  \


#define INFO(logger) LOGGER_STREAM_LEVEL(logger, spdlog::level::level_enum::info)

/*
%v	实际需要被日志记录的文本，如果文本中有{占位符}会被替换
%t	线程标识符
%P	进程标识符
%n	日志记录器名称
%l	日志级别
%L	日志级别简写
%a	简写的周几，例如Thu
%A	周几，例如Thursday
%b	简写的月份，例如Aug
%B	月份，例如August
%c	日期时间，例如Thu Aug 23 15:35:46 2014
%C	两位年份，例如14
%Y	四位年份，例如2014
%D 或 %x	MM/DD/YY格式日期，例如"08/23/14
%m	月份，1-12之间
%d	月份中的第几天，1-31之间
%H	24小时制的小时，0-23之间
%I	12小时制的小时，1-12之间
%M	分钟，0-59
%S	秒，0-59
%e	当前秒内的毫秒，0-999
%f	当前秒内的微秒，0-999999
%F	当前秒内的纳秒， 0-999999999
%p	AM或者PM
%r	12小时时间，例如02:55:02 pm
%R	等价于%H:%M，例如23:55
%T 或 %X	HH:MM:SS
%z	时区UTC偏移，例如+02:00
%+	表示默认格式

 * */

class Logger {
public:
    Logger(const std::string &name, const std::string &pattern = "%^[%Y-%m-%d %T] %n: [%s:%#] %v%$",
           spdlog::level::level_enum level = spdlog::level::trace);

    void log(spdlog::level::level_enum level, const char *format, ...);

    void setLevel(spdlog::level::level_enum level);

    void setPattern(const std::string &pattern);

    void setSaveDir(const std::string &path);

    spdlog::level::level_enum getLevel() const;

    std::shared_ptr<spdlog::logger> getLogger() const;

    template<typename T>
    Logger &operator<<(const T &data) {
        if (m_logger) {
            std::ostringstream oss;
            oss << data;
            m_logger->log(m_logger->level(), oss.str());
        }
        return *this;
    }

private:
    std::shared_ptr<spdlog::logger> m_logger;
    std::shared_ptr<spdlog::sinks::basic_file_sink_mt> m_fileAppender;
};

class LoggerManager {
public:
    static Logger &getLogger(const std::string &name);

private:
    static std::unordered_map<std::string, std::shared_ptr<Logger>> m_loggers;
};


bool createDirectory(const std::string &path);

std::string getTimeStamp();

std::string getTodayStamp();

#endif //VIDEOMANPLAT_ILOG_HPP
