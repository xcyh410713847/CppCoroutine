/*************************************************************************
**文件: src\Coroutine.h
**作者: shyfan
**日期: 2024/04/12 11:25:41
**功能: 协程
*************************************************************************/

#include <chrono>
#include <coroutine>
#include <iostream>
#include <thread>

// 协程的返回对象
template <typename T>
struct MyFuture
{
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;

    MyFuture(handle_type h) : coro_handle(h) {}
    ~MyFuture()
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
struct MyFuture<T>::promise_type
{
    T value;
    std::suspend_always initial_suspend() { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }
    auto get_return_object()
    {
        return MyFuture<T>{handle_type::from_promise(*this)};
    }
    void return_value(T v) { value = v; } // 设置协程返回值
    void unhandled_exception()
    {
        std::exit(1); // 简单处理异常：直接退出程序
    }
};

// 异步等待一段时间
MyFuture<int> async_wait(int seconds)
{
    // 模拟异步操作，简单地等一段时间
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    co_return 42; // 协程最终返回的结果
}
