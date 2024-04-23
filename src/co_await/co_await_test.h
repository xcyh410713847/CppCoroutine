/*************************************************************************
**文件: src\co_await\co_await_test.h
**作者: shyfan
**日期: 2024/04/18 19:50:49
**功能: co_await 打印协程的各个函数调用
*************************************************************************/

#include <coroutine>
#include <iostream>

// 协程的返回对象
struct co_await_return
{
    co_await_return()
    {
        std::cout << "co_await_return " << this << " co_await_return" << std::endl;
    }

    ~co_await_return()
    {
        std::cout << "co_await_return " << this << " ~co_await_return" << std::endl;
    }

    bool await_ready() const noexcept
    {
        std::cout << "co_await_return " << this << " await_ready" << std::endl;
        // false表示需要挂起
        return false;
    }

    void await_suspend(std::coroutine_handle<> h) const noexcept
    {
        // 挂起当前协程
        std::cout << "co_await_return " << this << " await_suspend" << std::endl;
        std::cout << "co_await_return await_suspend h " << &h << std::endl;
        std::cout << "co_await_return await_suspend h.address " << h.address() << std::endl;
    }

    void await_resume() const noexcept
    {
        // 恢复当前协程
        std::cout << "co_await_return " << this << " await_resume" << std::endl;
    }
};

// 协程的返回对象
struct co_await_test
{
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;

    co_await_test(handle_type h) : coro_handle(h)
    {
        std::cout << "co_await_test " << this << " co_await_test" << std::endl;
        std::cout << "co_await_test co_await_test h " << &h << std::endl;
        std::cout << "co_await_test co_await_test h.address " << h.address() << std::endl;
        std::cout << "co_await_test co_await_test coro_handle " << &coro_handle << std::endl;
        std::cout << "co_await_test co_await_test coro_handle.address " << coro_handle.address() << std::endl;
    }

    ~co_await_test()
    {
        std::cout << "co_await_test " << this << " ~co_await_test" << std::endl;
    }

    handle_type coro_handle;
};

struct co_await_test::promise_type
{
    auto get_return_object()
    {
        std::cout << "co_await_test::promise_type " << this << " get_return_object" << std::endl;
        return co_await_test{co_await_test::handle_type::from_promise(*this)};
    }
    std::suspend_never initial_suspend()
    {
        std::cout << "co_await_test::promise_type " << this << " initial_suspend" << std::endl;
        return {};
    }
    std::suspend_never final_suspend() noexcept
    {
        std::cout << "co_await_test::promise_type " << this << " final_suspend" << std::endl;
        return {};
    }
    void return_void()
    {
        std::cout << "co_await_test::promise_type " << this << " return_void" << std::endl;
    }
    void unhandled_exception()
    {
        std::cout << "co_await_test::promise_type " << this << " unhandled_exception" << std::endl;
        std::exit(1);
    }
};

co_await_test co_await_test_create()
{
    auto co = co_await_return{};
    std::cout << "co_await_test_create " << &co << std::endl;
    co_await co;
}
