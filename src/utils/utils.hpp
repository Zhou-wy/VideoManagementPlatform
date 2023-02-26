/*
 * @description:
 * @version:
 * @Author: zwy
 * @Date: 2022-10-17 17:03:17
 * @LastEditors: zwy
 * @LastEditTime: 2022-10-31 17:29:42
 */
#ifndef __HTTP_SERVER_UTIL_H__
#define __HTTP_SERVER_UTIL_H__
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdint.h>
#include <cassert>
#include <cxxabi.h>
#include <typeinfo>

namespace zwy
{
    pid_t GetThreadId();
    uint32_t GetFiberId();
    template <class T>
    const char *TypeToName()
    {
        static const char *s_name = abi::__cxa_demangle(typeid(T).name(), nullptr, nullptr, nullptr);
        return s_name;
    }
};
#endif