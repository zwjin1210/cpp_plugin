#pragma once
#include <iostream>
#include "plugin_base.h"

struct PluginA:public PluginBaseT<PluginA> {
    void Init() override{
        std::cout << "PluginA Init" << std::endl;
    }
    void Run() override{
        std::cout << "PluginA Run" << std::endl;
    }
};

DLL_EXPORT  PluginA *CreatePlugin(){
        static PluginA *retval = new PluginA();
        return retval;
}