
#include "../../include/plugins/PluginLoader.hpp"
#include "../../include/rayTracerError.hpp"

namespace RayTracer {
    PluginLoader::PluginLoader(const std::string& library_path) {
        handle_ = dlopen(library_path.c_str(), RTLD_LAZY);
        if (!handle_) {
            throw RayTracerError("Failed to load library: " + library_path);
        }
    }

    PluginLoader::~PluginLoader() {
        if (handle_) {
            dlclose(handle_);
        }
    }

    void *PluginLoader::loadsymbols(const std::string& sym_name) const {
        if (!handle_) {
            throw RayTracerError("Library not loaded");
        }
        void* func_ptr = dlsym(handle_, sym_name.c_str());
        if (!func_ptr) {
            throw RayTracerError("Symbol not found: " + sym_name);
        }
        return func_ptr;
    }
}