/*
 * @description:
 * @version:
 * @Author: zwy
 * @Date: 2022-10-17 17:03:17
 * @LastEditors: zwy
 * @LastEditTime: 2022-10-31 17:29:46
 */
#include "utils.hpp"

namespace zwy
{
    pid_t GetThreadId()
    {
        return syscall(SYS_gettid);
    }
    uint32_t GetFiberId()
    {
        return 0;
    }
}