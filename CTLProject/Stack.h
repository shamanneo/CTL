#pragma once
#include "Node.h"

template <typename T>
class Stack
{
    private : 
        int m_size ; 
        Node<T> *m_head ; 
    public :
        Stack() ;
        Stack(const Stack<T> &s) ; 
        ~Stack() ; 
    public : 
        bool Empty() const ; 
        int Size() const ; 
        void Push(const T &&t) ; 
        void Pop() ;
        T &Top() const ; 
        Stack &operator = (const Stack<T> &s) ; 
} ;

template <typename T>
Stack<T>::Stack()
{
    m_size = 0 ; 
    m_head = nullptr ; 
}

template <typename T>
Stack<T>::Stack(const Stack<T> &s)
{
    this = s ; 
}

template <typename T>
Stack<T>::~Stack()
{

}

template <typename T>
bool Stack<T>::Empty() const 
{
    return (m_size == 0) ? true : false ; 
}

template <typename T>
int Stack<T>::Size() const 
{
    return m_size ; 
}

template <typename T>
void Stack<T>::Push(const T &&t)
{
    
}

template <typename T>
void Stack<T>::Pop() 
{

}

template <typename T>
T &Stack<T>::Top() const 
{

} 

template <typename T>
Stack<T> &Stack<T>::operator = (const Stack<T> &s)
{
    this->m_head = s.m_head ; 
    return this ; 
}

