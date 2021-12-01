#pragma once
#include"List.h"

template <typename T>
class Deque
{
    private :   
        List<T> *m_my_list ; 
    public :
        Deque() ;
        Deque(const Deque &other) ; 
        ~Deque() ; 
    public :
        int Size() const ;
        bool Empty() const ; 
        T &Front() const ; 
        T &Back() const ;
        void PushFront(const T &&t) ; 
        void PushBack(const T &&t) ; 
        void PopFront() ; 
        void PopBack() ; 
        void Clear() ; 
        Deque<T> &operator = (const Deque<T> &other) ; 
        // T &operator [] (int index) ;  
} ; 

template <typename T>
Deque<T>::Deque()
    : m_my_list(new List<T>) 
{

}

template <typename T>
Deque<T>::Deque(const Deque &other)
{
    *this = other ; 
}

template <typename T>
Deque<T>::~Deque()
{
    delete m_my_list ; 
}

template <typename T>
int Deque<T>::Size() const  
{
    return m_my_list->Size() ; 
}

template <typename T>
bool Deque<T>::Empty() const  
{
    return (m_my_list->Size() == 0) ? true : false ;
}

template <typename T>
T &Deque<T>::Front() const 
{
    return m_my_list->Front() ; 
}

template <typename T>
T &Deque<T>::Back() const 
{
    return m_my_list->Back() ; 
}

template <typename T>
void Deque<T>::PushFront(const T &&t) 
{
    m_my_list->PushFront((T)t) ; 
}

template <typename T>
void Deque<T>::PushBack(const T &&t) 
{
    m_my_list->PushBack((T)t) ; 
}

template <typename T>
void Deque<T>::PopFront()
{
    m_my_list->PopFront() ;
}

template <typename T>
void Deque<T>::PopBack()
{
    m_my_list->PopBack() ;
}

template <typename T>
void Deque<T>::Clear()
{
    m_my_list->Clear() ; 
}

template <typename T>
Deque<T> &Deque<T>::operator = (const Deque<T> &other) 
{
    this->m_my_list->operator=(*other.m_my_list) ; 
    return *this ; 
}

/*
template <typename T>
T &Deque<T>::operator [] (int index) 
{
    List<T> *temp_list = this->m_my_list ; 
    for(int i = 0 ; i < index ; i++)
    {
        temp_list->PopFront() ;
    }
    return 
}
*/
        

