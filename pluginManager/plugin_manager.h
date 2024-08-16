#pragma once
#include <vector>
#include <string>
#include <dlfcn.h>

#include "plugin_base.h"


struct PluginManager
{
    void create_plugin(std::string cfg);
    std::vector<PluginBase *> plugin_list;
};
