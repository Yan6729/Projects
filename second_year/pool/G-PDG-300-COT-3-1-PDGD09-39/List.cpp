/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** List
*/

#include "List.hpp"

List::List()
{
    _head = nullptr;
}

List::~List()
{
}

List::InvalidOperationException::InvalidOperationException(std::string msg)
{
    message = msg;
}

List::InvalidOperationException::~InvalidOperationException()
{}

const char *List::InvalidOperationException::what(void) const noexcept
{
    return message.c_str();
}

void List::pushFront(IObject *obj)
{
    Node *newNode = new Node();
    newNode->_obj = obj;
    newNode->prev_obj = nullptr;
    newNode->next_obj = _head;

    if (_head != nullptr)
        _head->prev_obj = newNode;

    _head = newNode;
}

void List::pushBack(IObject *obj)
{
    Node *newNode = new Node();
    newNode->_obj = obj;
    newNode->next_obj = nullptr;

    if (_head == nullptr) {
        newNode->prev_obj = _head;
        _head = newNode;
        return;
    }

    Node *temp = _head;
    while (temp->next_obj == nullptr) {
        temp = temp->next_obj;
    }

    temp->next_obj = newNode;
    newNode->prev_obj = temp;
}

void List::popFront(void)
{
    if (_head == nullptr) {
        throw List::InvalidOperationException("Invalid Operation: The listt is actually empty");
        return;
    }

    Node *tmp = _head;
    _head = _head->next_obj;

    if (_head != nullptr) {
        _head->prev_obj = nullptr;
    }
    delete(tmp);
}

void List::popBack(void)
{
    if (_head == nullptr) {
        throw List::InvalidOperationException("Invalid Operation: The listt is actually empty");
        return;
    }

    Node *tmp = _head;
    while(tmp->next_obj != nullptr) {
        tmp = tmp->next_obj;
    }

    if (tmp->prev_obj != nullptr) {
        tmp->prev_obj->next_obj = nullptr;
    } else {
        _head = nullptr;
    }
    delete(_head);
}

std::size_t List::size(void) const
{
    std::size_t size = 0;
    
    Node *tmp = _head;

    while(tmp != nullptr) {
        size += 1;
    }
    return size;
}

bool List::empty(void) const
{
    std::size_t size_ = size();

    if (size_ == 0) {
        return true;
    }
    return false;
}

IObject *& List::front(void)
{
    std::size_t size_ = size();

    if (size_ == 0) {
        throw List::InvalidOperationException("Invalid Operation: The listt is actually empty");
    }
    return _head->_obj;
}

IObject* List::front(void) const
{
    std::size_t size_ = size();

    if (size_ == 0) {
        throw List::InvalidOperationException("Invalid Operation: The listt is actually empty");
    }
    return _head->_obj;
}

IObject*& List::back(void)
{
    std::size_t size_ = size();

    if (size_ == 0) {
        throw List::InvalidOperationException("Invalid Operation: The listt is actually empty");
    }

    Node *tmp = _head;
    while(tmp->next_obj != nullptr) {
        tmp = tmp->next_obj;
    }
    return tmp->_obj;
}

IObject* List::back(void) const
{
    std::size_t size_ = size();

    if (size_ == 0) {
        throw List::InvalidOperationException("Invalid Operation: The listt is actually empty");
    }

    Node *tmp = _head;
    while(tmp->next_obj != nullptr) {
        tmp = tmp->next_obj;
    }
    return tmp->_obj;
}

void List::clear(void)
{
    if (_head == nullptr) {
        throw List::InvalidOperationException("Invalid Operation: The listt is already empty");
        return;
    }
    while (_head != nullptr) {
        delete(_head);
        _head = _head->next_obj;
    }
    _head = nullptr;
}

void List::forEach(void(*function)(IObject*))
{
    if (_head == nullptr) {
        throw List::InvalidOperationException("Invalid operation: Can't apply a function on empty list");
    }
    Node *tmp = _head;

    while(tmp != nullptr) {
        function(tmp->_obj);
        tmp = tmp->next_obj;
    }
    return;
}
