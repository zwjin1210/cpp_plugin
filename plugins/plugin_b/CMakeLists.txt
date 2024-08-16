# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 将源文件添加到库中
add_library(plugin_b SHARED plugin_b.cpp)

# 指定插件库的头文件路径
target_include_directories(plugin_b PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
