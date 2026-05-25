/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** UniquePointer
*/

#ifndef UNIQUEPOINTER_HPP_
    #include <iostream>
    #include <string>
    #include <memory>
    #define UNIQUEPOINTER_HPP_

template <typename Type>
class UniquePointer {
    public:
        UniquePointer(Type *ptr) : _ptr(ptr) {};
        UniquePointer() : _ptr(nullptr) {};
        UniquePointer(const UniquePointer& other) = delete;
        UniquePointer(UniquePointer&& other) = delete;
        UniquePointer& operator=(UniquePointer& other) = delete;
        UniquePointer& operator=(UniquePointer&& other) = delete;
        Type* operator->() const
        {
            return _ptr;
        };
        Type operator*() const
        {
            return *_ptr;
        }
        
        UniquePointer& operator=(Type *ptr) {
            if (_ptr != nullptr)
                delete(_ptr);
            _ptr = ptr;
            return *this;
        };
        
        ~UniquePointer() {
            if (_ptr != nullptr) {
                delete(_ptr);
            }
            _ptr = nullptr;
        };

        void reset() {
            if (_ptr != nullptr) {
                delete(_ptr);
            }
            _ptr = nullptr;
        };

        void reset(Type *ptr) {
            if (_ptr != nullptr) {
                delete(_ptr);
            }
            _ptr = ptr;

        };


        Type *get() {
            return _ptr;
        };

    private:
        Type *_ptr;
};

#endif /* !UNIQUEPOINTER_HPP_ */
