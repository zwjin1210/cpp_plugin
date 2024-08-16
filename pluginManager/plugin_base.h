#pragma once

#if defined(_WIN32) || defined(_WIN64)
#define DLL_EXPORT  extern "C" __declspec(dllexport) 
#endif

#if defined(__unix__) || defined(unix)  
#define DLL_EXPORT  extern "C" 
#endif
// 非模板基类，提供一个虚函数接口
struct PluginBase {
    virtual void Init() = 0; // 纯虚函数，要求派生类必须实现
    virtual void Run() = 0; // 纯虚函数，要求派生类必须实现
    virtual ~PluginBase() {}   // 虚析构函数
};

// 模板基类，通过 CRTP 实现静态多态性
template <typename T>
struct PluginBaseT : public PluginBase {
    void Init() override {
        static_cast<T*>(this)->Init();
    }
    void Run() override {
        static_cast<T*>(this)->Run();
    }
};

