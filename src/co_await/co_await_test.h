/*************************************************************************
**文件: src\co_await\co_await_test.h
**作者: shyfan
**日期: 2024/04/18 19:50:49
**功能: co_await 打印协程的各个函数调用
*************************************************************************/

#include <coroutine>
#include <iostream>

// 协程的返回对象
struct co_await_test
{
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;

    co_await_test()
    {
        std::cout << "co_await_test " << this << " co_await_test" << std::endl;
    }

    ~co_await_test()
    {
        std::cout << "co_await_test " << this << " ~co_await_test" << std::endl;
    }

    bool await_ready() const noexcept
    {
        std::cout << "co_await_test " << this << " await_ready" << std::endl;
        // false表示需要挂起
        return false;
    }

    void await_suspend(handle_type h) const noexcept
    {
        // 挂起当前协程
        std::cout << "co_await_test " << this << " await_suspend" << std::endl;
    }

    void await_resume() const noexcept
    {
        // 恢复当前协程
        std::cout << "co_await_test " << this << " await_resume" << std::endl;
    }
};

struct co_await_test::promise_type
{
    auto get_return_object()
    {
        std::cout << "co_await_test " << this << " get_return_object" << std::endl;
        return co_await_test{};
    }
    std::suspend_never initial_suspend()
    {
        std::cout << "co_await_test " << this << " initial_suspend" << std::endl;
        return {};
    }
    std::suspend_never final_suspend() noexcept
    {
        std::cout << "co_await_test " << this << " final_suspend" << std::endl;
        return {};
    }
    void return_void()
    {
        std::cout << "co_await_test " << this << " return_void" << std::endl;
    }
    void unhandled_exception()
    {
        std::cout << "co_await_test " << this << " unhandled_exception" << std::endl;
        std::exit(1);
    }
};

co_await_test co_await_test_create()
{
    co_await co_await_test{};
}
