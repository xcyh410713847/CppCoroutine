/*************************************************************************
**文件: src\co_return\co_return_test1.h
**作者: shyfan
**日期: 2024/04/17 20:21:20
**功能: co_return_test1
*************************************************************************/

#include <coroutine>

// 协程的返回对象
template <typename T>
struct co_return_test1
{
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;

    co_return_test1(handle_type h) : coro_handle(h) {}
    ~co_return_test1()
    {
        if (coro_handle)
            coro_handle.destroy();
    }

    T get()
    { // 获取异步结果
        if (coro_handle)
        {
            coro_handle.resume();
        }
        return coro_handle.promise().value;
    }

    handle_type coro_handle;
};

template <typename T>
struct co_return_test1<T>::promise_type
{
    T value;
    std::suspend_always initial_suspend() { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }
    auto get_return_object()
    {
        return co_return_test1<T>{handle_type::from_promise(*this)};
    }
    void return_value(T v) { value = v; } // 设置协程返回值
    void unhandled_exception()
    {
        std::exit(1); // 简单处理异常：直接退出程序
    }
};

// 创建协程
template <typename T>
co_return_test1<T> co_return_test1_create(T value)
{
    co_return value; // 协程最终返回的结果
}
