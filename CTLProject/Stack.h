#pragma once
#include "List.h"

template <typename T>
class Stack
{
    private : 
        int m_size ; 
        List<T> m_my_list ; 
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
    : m_size(0), m_my_list(new List<T>) 
{
    
}

template <typename T>
Stack<T>::Stack(const Stack<T> &s)
{
    this->m_my_list = s.m_my_list ; 
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

}

