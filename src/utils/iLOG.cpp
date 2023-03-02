//
// Created by zwy on 2023/3/2.
//

#include "iLOG.hpp"
#include <sstream>
#include <iomanip>
#include <windows.h>
#include <iostream>
#include <chrono>


Logger::Logger(const std::string &name, const std::string &pattern, spdlog::level::level_enum level) {
    spdlog::set_pattern(pattern);
    spdlog::set_level(level);

    m_logger = spdlog::stdout_color_mt(name);
    m_logger->set_level(level);
}


void Logger::log(const spdlog::level::level_enum level, const char *format, ...) {
    if (m_logger) {
        va_list args;
        va_start(args, format);
        char buffer[1024];
        int len = std::vsnprintf(buffer, sizeof(buffer), format, args);
        va_end(args);
        if (len > 0) {
            m_logger->log(level, std::string(buffer, len));
        }
    }
}

void Logger::setLevel(const spdlog::level::level_enum level) {
    m_logger->set_level(level);
}

void Logger::setPattern(const std::string &pattern) {
    m_logger->set_pattern(pattern);
}

spdlog::level::level_enum Logger::getLevel() const {
    return m_logger->level();
}

std::shared_ptr<spdlog::logger> Logger::getLogger() const {
    return m_logger;
}

void Logger::setSaveDir(const std::string &path) {
    std::string saveDir = path + "/" + getTodayStamp();
    createDirectory(saveDir);
    std::string fileName = saveDir + "/" + getTimeStamp();
    m_fileAppender = std::make_shared<spdlog::sinks::basic_file_sink_mt>(fileName + ".log", true);
    m_fileAppender->set_level(m_logger->level());
    m_logger->sinks().emplace_back(m_fileAppender);
}


std::unordered_map<std::string, std::shared_ptr<Logger>> LoggerManager::m_loggers;

Logger &LoggerManager::getLogger(const std::string &name) {
    auto it = m_loggers.find(name);
    if (it == m_loggers.end()) {
        auto logger = std::make_shared<Logger>(name);
        it = m_loggers.emplace(name, logger).first;
    }

    return *(it->second);
}


bool createDirectory(const std::string &path) {
    if (CreateDirectory(path.c_str(), NULL) || GetLastError() == ERROR_ALREADY_EXISTS) {
        return true; // 目录创建成功或已存在
    } else {
        // 获取父目录路径
        size_t pos = path.find_last_of("/\\");
        if (pos != std::string::npos) {
            std::string parent_dir = path.substr(0, pos);
            // 递归创建父目录
            if (createDirectory(parent_dir)) {
                // 创建当前目录
                return CreateDirectory(path.c_str(), NULL) || GetLastError() == ERROR_ALREADY_EXISTS;
            } else {
                return false;
            }
        } else {
            return false; // 路径不合法
        }
    }
}

std::string getTimeStamp() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << ltm->tm_hour << "-"
        << std::setfill('0') << std::setw(2) << ltm->tm_min << "-"
        << std::setfill('0') << std::setw(2) << ltm->tm_sec;
    return oss.str();
}

std::string getTodayStamp(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(4) << 1900 + ltm->tm_year  << "-"
        << std::setfill('0') << std::setw(2) << 1 + ltm->tm_mon << "-"
        << std::setfill('0') << std::setw(2) << ltm->tm_mday;
    return oss.str();
}

