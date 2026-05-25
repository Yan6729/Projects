/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** UniquePointer
*/

#ifndef UNIQUEPOINTER_HPP_
    #include "IObject.hpp"
    #include <type_traits>
    #define UNIQUEPOINTER_HPP_

class UniquePointer {
    public:
        UniquePointer();
        UniquePointer(IObject *object);
        UniquePointer(const UniquePointer& other) = delete;
        UniquePointer(const UniquePointer&& other) = delete;
        UniquePointer& operator=(const UniquePointer& other) = delete;
        UniquePointer& operator=(IObject *object);
        void reset(IObject* object);
        void reset(void);
        void swap(UniquePointer& other);
        ~UniquePointer();

    private:
        IObject *_ptr = nullptr;
};

#endif /* !UNIQUEPOINTER_HPP_ */
