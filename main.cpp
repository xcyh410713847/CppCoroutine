/*************************************************************************
**文件: main.cpp
**作者: shyfan
**日期: 2024/04/12 11:20:04
**功能: 主函数
*************************************************************************/

#include <iostream>

#include "SkywalkerCoroutine/SkywalkerCoroutine.h"

#include "co_await/co_await.h"
#include "co_return/co_return.h"
#include "co_yield/co_yield.h"

SkywalkerCo_Create(SkywalkerCoTest);

int main()
{
    SkywalkerCoTest co = SkywalkerCoTestCreate();
    co.get();
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    test_co_return();
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    test_co_await();
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    co_yield_test();

    return 0;
}
