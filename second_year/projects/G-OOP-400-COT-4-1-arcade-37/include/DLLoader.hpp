#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <stdexcept>
#include <string>
#include <dlfcn.h>

namespace Arcade {

class DLLoader {
public:
    explicit DLLoader(const std::string &path)
        : _path(path), _handle(nullptr)
    {
        _handle = dlopen(path.c_str(), RTLD_LAZY);
        if (!_handle)
            throw std::runtime_error(std::string("DLLoader: ") + dlerror());
    }

    ~DLLoader()
    {
        if (_handle)
            dlclose(_handle);
    }

    DLLoader(const DLLoader &)            = delete;
    DLLoader &operator=(const DLLoader &) = delete;

    DLLoader(DLLoader &&o) noexcept
        : _path(std::move(o._path)), _handle(o._handle)
    {
        o._handle = nullptr;
    }

    template <typename Func>
    Func getSymbol(const std::string &name) const
    {
        dlerror();
        void       *sym = dlsym(_handle, name.c_str());
        const char *err = dlerror();
        if (err)
            throw std::runtime_error("DLLoader::getSymbol '" + name + "': " + err);
        Func fn;
        *reinterpret_cast<void **>(&fn) = sym;
        return fn;
    }

    const std::string &path() const { return _path; }

private:
    std::string _path;
    void       *_handle;
};

}

#endif
