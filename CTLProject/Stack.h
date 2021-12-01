#pragma once
#include "List.h"

template <typename T>
class Stack
{
    private : 
        List<T> *m_my_list ; 
    public :
        Stack() ;
        Stack(const Stack<T> &other) ; 
        ~Stack() ; 
    public : 
        bool Empty() const ; 
        int Size() const ; 
        void Push(const T &&t) ; 
        void Pop() ;
        T &Top() const ; 
        Stack &operator = (const Stack<T> &other) ; 
} ;

template <typename T>
Stack<T>::Stack()
    : m_my_list(new List<T>) 
{
    
}

template <typename T>
Stack<T>::Stack(const Stack<T> &other)
    : Stack()
{
    *this = other ; 
}

template <typename T>
Stack<T>::~Stack()
{
    delete m_my_list ; 
}

template <typename T>
bool Stack<T>::Empty() const 
{
    return (m_my_list->m_size == 0) ? true : false ; 
}

template <typename T>
int Stack<T>::Size() const 
{
    return m_my_list->m_size ; 
}

template <typename T>
void Stack<T>::Push(const T &&t)
{
    m_my_list->PushFront((T)t) ; 
}

template <typename T>
void Stack<T>::Pop() 
{
    m_my_list->PopFront() ; 
}

template <typename T>
T &Stack<T>::Top() const 
{
    return m_my_list->Front() ;
} 

template <typename T>
Stack<T> &Stack<T>::operator = (const Stack<T> &other)
{
    this->m_my_list->operator=(*other.m_my_list) ;
    return *this ; 
}

