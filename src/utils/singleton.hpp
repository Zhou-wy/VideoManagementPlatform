/*
 * @description:
 * @version:
 * @Author: zwy
 * @Date: 2022-10-18 10:08:12
 * @LastEditors: zwy
 * @LastEditTime: 2022-10-31 17:29:49
 */
#ifndef __HTTP_SERVER_SINGLETON_H__
#define __HTTP_SERVER_SINGLETON_H__

#include <memory>

namespace zwy
{
    // 单例模式
    template <class T, class X = void, int N = 0>
    class Singleton
    {
    public:
        static T *GetInstance()
        {
            static T v;
            return &v;
        }
    };
    template <class T, class X = void, int N = 0>
    class SingletonPtr
    {
    public:
        static std::shared_ptr<T> GetInstance()
        {
            static std::shared_ptr<T> v(new T);
            return v;
        }
    };
}

#endif