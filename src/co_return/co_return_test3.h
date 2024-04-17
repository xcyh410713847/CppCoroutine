/*************************************************************************
**文件: src\co_return\co_return_test3.h
**作者: shyfan
**日期: 2024/04/17 20:49:16
**功能: co_return_test3 多个返回值
*************************************************************************/

#include <coroutine>

// 协程的返回对象
template <typename... Ts>
struct co_return_test3
{
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;

    co_return_test3(handle_type h) : coro_handle(h) {}
    ~co_return_test3()
    {
        if (coro_handle)
            coro_handle.destroy();
    }

    /**
     * 获取协程的返回值
     */
    std::tuple<Ts...> get()
    {
        if (coro_handle)
        {
            coro_handle.resume();
        }
        return coro_handle.promise().value;
    }

    void getNoReturn()
    {
        if (coro_handle)
        {
            coro_handle.resume();
        }
    }

    handle_type coro_handle;
};

template <typename... Ts>
struct co_return_test3<Ts...>::promise_type
{
    /**
     * 协程的返回值
     */
    std::tuple<Ts...> value;

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
        return co_return_test3<Ts...>{handle_type::from_promise(*this)};
    }

    /**
     * 协程的返回值
     */
    void return_value(std::tuple<Ts...> v)
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

template <typename... Ts>
co_return_test3<Ts...> co_return_test3_create(Ts... ts)
{
    co_return std::make_tuple(ts...);
}
