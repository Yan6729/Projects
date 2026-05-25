/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** SharedPointer
*/

#ifndef SHAREDPOINTER_HPP_
    #include <iostream>
    #include <string>
    #define SHAREDPOINTER_HPP_

template <typename Type>
class SharedPointer {
    public:
        SharedPointer() : _ptr(nullptr), _count(nullptr) {};
        SharedPointer(Type *ptr) : _ptr(ptr) {
            if (ptr != nullptr) {
                _count = new int(1);
            } else {
                _count = nullptr;
            }
        };
        SharedPointer(const SharedPointer& other) {
            _ptr = other._ptr;
            _count = other._count;
            if (_count)
                (*_count) += 1;
        };
        
        SharedPointer& operator=(const SharedPointer& other) {
            if (this != &other) {
                if (_count != nullptr) {
                    (*_count) -= 1;
                    if ((*_count) == 0) {
                        delete(_ptr);
                        delete(_count);
                    }
                }
                _ptr = other._ptr;
                _count = other._count;
                if (_count)
                    (*_count) += 1;
            }
            return *this;
        };
        ~SharedPointer() {
            if (_count != nullptr) {
                (*_count) -= 1;
                if ((*_count) == 0) {
                    delete(_ptr);
                    delete(_count);
                }
            }
            _ptr = nullptr;
            _count = nullptr;
        };
        Type* operator->() const
        {
            return _ptr;
        };
        Type operator*() const
        {
            return *_ptr;
        }
        
        SharedPointer& operator=(Type *ptr) {
            if (_count != nullptr) {
                (*_count) -= 1;
                if ((*_count) == 0) {
                    delete(_ptr);
                    delete(_count);
                }
            }
             _ptr = ptr;
            if (ptr == nullptr)
                _count = nullptr;
            else
                _count = new int(1);
            return *this;
        };

        void reset() {
            if (_count != nullptr) {
                (*_count) -= 1;
                if ((*_count) == 0) {
                    delete(_ptr);
                    delete(_count);
                }
            }
            _ptr = nullptr;
            _count = nullptr;
        };

        void reset(Type *ptr) {
            if (_count != nullptr) {
                (*_count) -= 1;
                if ((*_count) == 0) {
                    delete(_ptr);
                    delete(_count);
                }
            }
            _ptr = ptr;
            if (ptr != nullptr) {
                _count = new int(1);
            } else {
                _count = nullptr;
            }

        };

        Type *get() {
            return _ptr;
        };

    private:
        Type *_ptr;
        int *_count = nullptr;
};

#endif /* !SHAREDPOINTER_HPP_ */
