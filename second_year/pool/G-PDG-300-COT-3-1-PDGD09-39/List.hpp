/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** List
*/

#ifndef LIST_HPP_
    #include <iostream>
    #include <string>
    #include "IObject.hpp"
    #include <cstring>
    #define LIST_HPP_

class Node {
    public:
        IObject *_obj = nullptr;
        Node *next_obj = nullptr;
        Node *prev_obj = nullptr;
};

class List {
    public:
        class InvalidOperationException : public std::exception {
            public:
                InvalidOperationException(std::string message);
                ~InvalidOperationException();
                virtual const char *what(void) const noexcept override;

            private:
                std::string message;
        };
        List();
        List(List& other) = delete;
        List(List&& other) = delete;
        List& operator=(const List& other) = delete;
        ~List();
        bool empty(void) const;
        std::size_t size(void) const;
        IObject*& front(void);
        IObject* front(void) const;
        IObject*& back(void);
        IObject* back(void) const;
        void pushBack(IObject* obj);
        void pushFront(IObject* obj);
        void popFront(void);
        void popBack(void);
        void clear(void);
        void forEach(void(*function)(IObject*));
    
    private:
        Node *_head;
};

#endif /* !LIST_HPP_ */
