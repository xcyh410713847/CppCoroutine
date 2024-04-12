# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.26)

# 项目信息
set(project_name CppCoroutine)
project(${project_name})

# 设置C++标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 禁用编译器的扩展
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(
    ./src/
)

file(GLOB project_sources

    # cpp
    *.cpp
    src/*.cpp
    src/*/*.cpp

    # h
    *.h
    src/*.h
    src/*/*.h
)

# 生成可执行文件
add_executable(${project_name}
main.cpp
${project_sources})
