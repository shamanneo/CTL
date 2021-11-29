#pragma once
#include "List.h"

template <typename T>
class Queue
{
    private : 
        List<T> *m_my_list ; 
    public :
        Queue() ;
        Queue(const Queue<T> &s) ; 
        ~Queue() ; 
    public : 
        bool Empty() const ; 
        int Size() const ; 
        void Push(const T &&t) ; 
        void Pop() ;
        T &Top() const ; 
        Queue &operator = (const Queue<T> &s) ; 
} ;

template <typename T>
Queue<T>::Queue()
    : m_my_list(new List<T>) 
{
    
}

template <typename T>
Queue<T>::Queue(const Queue<T> &s)
    : Queue()
{
    *this = s ; 
}

template <typename T>
Queue<T>::~Queue()
{
    delete m_my_list ; 
}

template <typename T>
bool Queue<T>::Empty() const 
{
    return (m_my_list->m_size == 0) ? true : false ; 
}

template <typename T>
int Queue<T>::Size() const 
{
    return m_my_list->m_size ; 
}

template <typename T>
void Queue<T>::Push(const T &&t)
{
    m_my_list->PushFront((T)t) ; 
}

template <typename T>
void Queue<T>::Pop() 
{
    m_my_list->PopBack() ; 
}

template <typename T>
T &Queue<T>::Top() const 
{
    return m_my_list->Back() ;
} 

template <typename T>
Queue<T> &Queue<T>::operator = (const Queue<T> &s)
{
    this->m_my_list->operator=(*s.m_my_list) ; 
    return *this ; 
}

