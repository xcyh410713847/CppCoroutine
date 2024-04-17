/*************************************************************************
**文件: SkywalkerCoroutine\Include\SkywalkerCoroutine.h
**作者: shyfan
**日期: 2024/04/12 16:11:53
**功能: 协程
*************************************************************************/

#include <coroutine>
#include <iostream>

/**
 * 创建一个协程
 */
#define SkywalkerCo_Create(CoroutineName, ...)                       \
    struct CoroutineName                                             \
    {                                                                \
        struct promise_type;                                         \
        using handle_type = std::coroutine_handle<promise_type>;     \
        CoroutineName(handle_type h) : coro_handle(h) {}             \
        ~CoroutineName()                                             \
        {                                                            \
            if (coro_handle)                                         \
                coro_handle.destroy();                               \
        }                                                            \
        void get()                                                    \
        {                                                            \
            if (coro_handle)                                         \
                coro_handle.resume();                                \
            std::cout << "CoroutineName::get() called" << std::endl; \
        }                                                            \
        handle_type coro_handle;                                     \
    };                                                               \
    struct CoroutineName::promise_type                               \
    {                                                                \
        std::suspend_always initial_suspend() { return {}; }         \
        std::suspend_always final_suspend() noexcept { return {}; }  \
        auto get_return_object()                                     \
        {                                                            \
            return CoroutineName{handle_type::from_promise(*this)};  \
        }                                                            \
        void return_void() {}                                        \
        void unhandled_exception()                                   \
        {                                                            \
            std::exit(1);                                            \
        }                                                            \
    };                                                               \
    CoroutineName CoroutineName##Create(__VA_ARGS__)                 \
    {                                                                \
        co_return;                                                   \
    }
