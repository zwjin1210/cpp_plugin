#pragma once
#include <iostream>
#include "plugin_base.h"

struct PluginB:public PluginBaseT<PluginB> {
    void Init() override{
        std::cout << "PluginB Init" << std::endl;
    }
    void Run() override{
        std::cout << "PluginB Run" << std::endl;
    }
};

DLL_EXPORT PluginB *CreatePlugin(){
        static PluginB *retval = new PluginB();
        return retval;
}