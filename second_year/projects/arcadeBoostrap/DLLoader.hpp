/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
    #include <dlfcn.h>
    #include <iostream>
    #include <string>
    #include <vector>
    #include <memory>
    using namespace std;
    #define DLLOADER_HPP_ 

template <typename T>
class DLLoader {
    public:
        DLLoader(const string& path) {
            this->_handle = dlopen(path.c_str(), RTLD_LAZY);
        }

        ~DLLoader() {
            dlclose(this->_handle);
        }

        T* getInstance(const string& funcName) {
            auto func = (T *(*)())dlsym(this->_handle, funcName.c_str());
            return func();
        }

    private:
        void *_handle;
};

#endif /* !DLLOADER_HPP_ */
