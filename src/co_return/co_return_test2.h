/*************************************************************************
**文件: src\co_return\co_return_test2.h
**作者: shyfan
**日期: 2024/04/17 20:36:06
**功能: co_return_test2 两个返回值
*************************************************************************/

#include <coroutine>

// 协程的返回对象
template <typename T1, typename T2>
struct co_return_test2
{
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;

    co_return_test2(handle_type h) : coro_handle(h) {}
    ~co_return_test2()
    {
        if (coro_handle)
            coro_handle.destroy();
    }

    /**
     * 获取协程的返回值
     */
    std::pair<T1, T2> get()
    {
        if (coro_handle)
        {
            coro_handle.resume();
        }
        return coro_handle.promise().value;
    }

    handle_type coro_handle;
};

template <typename T1, typename T2>
struct co_return_test2<T1, T2>::promise_type
{
    /**
     * 协程的返回值
     */
    std::pair<T1, T2> value;

    /**
     * 协程的初始
     */
    std::suspend_always initial_suspend() { return {}; }

    /**
     * 协程的最终
     */
    std::suspend_always final_suspend() noexcept { return {}; }

    /**
     * 协程的返回对象
     */
    auto get_return_object()
    {
        return co_return_test2<T1, T2>{handle_type::from_promise(*this)};
    }

    /**
     * 协程的返回值
     */
    void return_value(std::pair<T1, T2> v)
    {
        value = v;
    }

    /**
     * 异常处理
     */
    void unhandled_exception()
    {
        std::exit(1); // 简单处理异常：直接退出程序
    }
};

template <typename T1, typename T2>
co_return_test2<T1, T2> co_return_test2_create(T1 v1, T2 v2)
{
    co_return std::make_pair(v1, v2);
}
