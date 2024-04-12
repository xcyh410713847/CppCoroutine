/*************************************************************************
**文件: main.cpp
**作者: shyfan
**日期: 2024/04/12 11:20:04
**功能: 主函数
*************************************************************************/

#include <iostream>

#include "src/Coroutine.h"

int main()
{
    MyFuture<int> result = async_wait(2); // 启动协程，等待2秒
    std::cout << "Waiting..." << std::endl;
    // 获取协程的结果
    std::cout << "Result: " << result.get() << std::endl;

    return 0;
}
