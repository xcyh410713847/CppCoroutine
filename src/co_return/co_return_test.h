/*************************************************************************
**文件: src\co_return\co_return_test.h
**作者: shyfan
**日期: 2024/04/17 21:01:26
**功能: co_return_test 不带返回值
*************************************************************************/

#include <coroutine>
#include <iostream>

// 协程的返回对象
struct co_return_test
{
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;

    co_return_test(handle_type h) : coro_handle(h)
    {
        std::cout << "co_return_test co_return_test" << std::endl;
    }
    ~co_return_test()
    {
        std::cout << "co_return_test ~co_return_test" << std::endl;
        if (coro_handle)
            coro_handle.destroy();
    }

    /**
     * 获取协程的返回值
     */
    void get()
    {
        std::cout << "co_return_test get" << std::endl;
        if (coro_handle)
        {
            coro_handle.resume();
        }
    }

    handle_type coro_handle;
};

struct co_return_test::promise_type
{
    /**
     * 协程的初始
     */
    std::suspend_always initial_suspend()
    {
        std::cout << "co_return_test initial_suspend" << std::endl;
        return {};
    }

    /**
     * 协程的最终
     */
    std::suspend_always final_suspend() noexcept
    {
        std::cout << "co_return_test final_suspend" << std::endl;
        return {};
    }

    /**
     * 协程的返回对象
     */
    auto get_return_object()
    {
        std::cout << "co_return_test get_return_object" << std::endl;
        return co_return_test{co_return_test::handle_type::from_promise(*this)};
    }

    /**
     * 协程的返回值
     */
    void return_void()
    {
        std::cout << "co_return_test return_void" << std::endl;
    }

    /**
     * 异常处理
     */
    void unhandled_exception()
    {
        std::cout << "co_return_test unhandled_exception" << std::endl;
        std::exit(1); // 简单处理异常：直接退出程序
    }
};

co_return_test co_return_test_create()
{
    co_return;
}
