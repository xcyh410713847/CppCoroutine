/*************************************************************************
**文件: src\co_await\co_await.h
**作者: shyfan
**日期: 2024/04/17 20:17:28
**功能: co_await
*************************************************************************/

/*
    协程 co_await
*/

#include <iostream>

#include "co_await_test.h"

void test_co_await()
{
    auto co = co_await_test_create();
    std::cout << "test_co_await " << &co << std::endl;
    std::cout << "test_co_await co.coro_handle " << &co.coro_handle << std::endl;
    std::cout << "test_co_await done: " << co.coro_handle.done() << std::endl; // 检查协程状态
}
