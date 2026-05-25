
#ifndef PLUGIN_FACTORY_HPP
#define PLUGIN_FACTORY_HPP

#include <unordered_map>
#include <memory>
#include <string>

#include "PluginLoader.hpp"
#include "../rayTracerError.hpp"

namespace RayTracer {

    template<typename T>
    class PluginFactory {
    public:

        using CreateFunc = T* (*)();
        using TypeFunc = const char* (*)();

        struct PluginData {
            std::unique_ptr<PluginLoader> loader;
            CreateFunc create;
        };

        void loadPlugin(const std::string& path) {
            auto loader = std::make_unique<PluginLoader>(path);

            auto create = reinterpret_cast<CreateFunc>(loader->loadsymbols("create"));
            auto getType = reinterpret_cast<TypeFunc>(loader->loadsymbols("getType"));
            std::string type = getType();
            PluginData data;
            data.loader = std::move(loader);
            data.create = create;
            plugins_[type] = std::move(data);
        }

        std::unique_ptr<T> create(const std::string& type) {
            auto it = plugins_.find(type);
            if (it == plugins_.end()) {
                throw RayTracerError("Plugin type not found: " + type);
            }
            return std::unique_ptr<T>(it->second.create());
        }

    private:
        std::unordered_map<std::string, PluginData> plugins_;
    };


}

#endif