cmake_minimum_required(VERSION 3.5.0)
project(cppPlugin VERSION 0.1.0 LANGUAGES C CXX)

# 设置库文件的生成目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs)

# 设置可执行文件的生成目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 指定插件管理器的头文件路径
include_directories(${CMAKE_SOURCE_DIR}/pluginManager)

# 包含插件子目录
add_subdirectory(plugins/plugin_a)
add_subdirectory(plugins/plugin_b)

add_executable(cppPlugin main.cpp pluginManager/plugin_manager.cpp)

