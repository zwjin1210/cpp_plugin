#include <stdio.h>
#include "plugin_manager.h"

int main(int, char**){
    PluginManager *m = new (PluginManager);
    if(m)
    {
        m->create_plugin("../libs/libplugin_a.so");
        m->create_plugin("../libs/libplugin_b.so");
        // 遍历插件列表并调用每个插件的 Init 和 Run 方法
        for (auto plugin : m->plugin_list) {
            if (plugin) {
                plugin->Init();
                plugin->Run();
            }
        }
        // 清理分配的内存
        for (auto plugin : m->plugin_list) {
            delete plugin;
        }

        delete m;
    }
    printf("Hello, from cppPlugin!\n");
}
