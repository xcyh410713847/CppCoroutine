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
#include "co_return_test2.h"
#include "co_return_test3.h"

void co_return_test()
{
    std::cout << "co_return_test" << std::endl;

    // 单个返回值
    auto co1_1 = co_return_test1_create<int>(9527);
    std::cout << "co1_1: " << co1_1.get() << std::endl;
    auto co1_2 = co_return_test1_create<std::string>("Hello World!");
    std::cout << "co1_2: " << co1_2.get() << std::endl;

    // 两个返回值
    auto co2_1 = co_return_test2_create<int, int>(9527, 2583);
    auto [a, b] = co2_1.get();
    std::cout << "co2_1: " << a << " " << b << std::endl;
    auto co2_2 = co_return_test2_create<std::string, std::string>("Hello", "World!");
    auto [c, d] = co2_2.get();
    std::cout << "co2_2: " << c << " " << d << std::endl;

    // 不定个返回值
    auto co3_1 = co_return_test3_create<int, int, int>(9527, 2583, 520);
    auto [e, f, g] = co3_1.get();
    std::cout << "co3_1: " << e << " " << f << " " << g << std::endl;
    auto co3_2 = co_return_test3_create<std::string, std::string, std::string>("Hello", "World", "!");
    auto [h, i, j] = co3_2.get();
    std::cout << "co3_2: " << h << " " << i << " " << j << std::endl;
    auto co3_3 = co_return_test3_create<int, std::string, double>(9527, "Hello", 3.14);
    auto [k, l, m] = co3_3.get();
    std::cout << "co3_3: " << k << " " << l << " " << m << std::endl;
    auto co3_4 = co_return_test3_create();
    co3_4.getNoReturn();
    std::cout << "co3_4" << std::endl;
}
