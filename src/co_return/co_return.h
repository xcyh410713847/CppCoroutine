/*************************************************************************
**文件: src\co_return\co_return.h
**作者: shyfan
**日期: 2024/04/17 20:17:41
**功能: co_return
*************************************************************************/

/*
    协程 co_return
*/

#include <iostream>

#include "co_return_test1.h"

void co_return_test()
{
    std::cout << "co_return_test" << std::endl;

    auto co1_1 = co_return_test1_create<int>(9527);
    std::cout << "co1_1: " << co1_1.get() << std::endl;
    auto co1_2 = co_return_test1_create<std::string>("Hello World!");
    std::cout << "co1_2: " << co1_2.get() << std::endl;
}
