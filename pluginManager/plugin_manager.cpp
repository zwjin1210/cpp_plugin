#include <iostream>
#include "plugin_manager.h"


void PluginManager::create_plugin(std::string cfg)
{
    PluginBase *(*func)();

    auto *handle = dlopen(cfg.c_str(),RTLD_LAZY);
    if(NULL == handle)
    {
        std::cout << "dlopen fail,please check path " << std::endl;
        return;
    }
    auto p = dlsym(handle,"CreatePlugin");

    if(p == NULL){
        std::cout << "Symbol not found:"<< dlerror() <<std::endl;
        return;
    }
    func = reinterpret_cast<PluginBase *(*)()>(p);
    PluginBase *impl = func();
    if(impl == NULL)
    {
        return;
    }
    plugin_list.push_back(impl);
}
