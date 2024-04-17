/*************************************************************************
**文件: main.cpp
**作者: shyfan
**日期: 2024/04/12 11:20:04
**功能: 主函数
*************************************************************************/

#include <iostream>

#include "SkywalkerCoroutine/SkywalkerCoroutine.h"

SkywalkerCo_Create(SkywalkerCoTest);

int main()
{
    SkywalkerCoTest co = SkywalkerCoTestCreate();
    co.get();

    return 0;
}
