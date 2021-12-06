#pragma once
#include "Node.h"

template <typename T>
class List
{
    private : 
        int m_size ; 
        Node<T> *m_header ; 
        Node<T> *m_trailer ; 
    private :
        void Link(Node<T> &next_node, Node<T> &new_node, Node<T> &prev_node) ; 
    public :    
        class Iterator // nested class.
        {
            private : 
                Node<T> *m_p ; 
            public : 
                Iterator() = default ; 
                Iterator(const Iterator &other) 
                {
                    *this = other ; 
                }
                Iterator(Node<T> *n)
                {
                    m_p = n ; 
                }
            public :    
                Iterator &operator ++ () 
                {
                    m_p = m_p->next ; 
                    return *this ; 
                }
                bool operator == (const Iterator &other) 
                {
                    return (this->m_p == other.m_p) ? true : false ; 
                }
                bool operator != (const Iterator &other) 
                {
                    return (this->m_p == other.m_p) ? false : true ; 
                }
                T &operator * ()
                {
                    return m_p->data ; 
                }
        } ; 
    public :
        explicit List(int size = 0) ;
        List(int size, const T &&t) ; 
        List(const List<T> &other) ; 
        ~List() ; 
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
        List &operator = (const List<T> &other) ; 
        List<T>::Iterator Begin() const 
        {
            Iterator it(m_header->next) ; 
            return it ;
        }
        List<T>::Iterator End() const
        {
            Iterator it(m_trailer) ; 
            return it ;
        }
} ; 

template <typename T>
List<T>::List(int size)
    : m_size(size), m_header(new Node<T>), m_trailer(new Node<T>) 
{
    m_header->next = m_trailer ; 
    m_trailer->prev = m_header ; 
}

template <typename T>
List<T>::List(int size, const T &&t)
    : List()
{
    for(int i = 0 ; i < size ; i++)
    {
        PushBack((T)t) ; 
    }
}

template <typename T>
List<T>::List(const List<T> &other)
    : List(other.m_size) 
{   
    *this = other ; 
}

template <typename T>
List<T>::~List()
{
    while(!Empty())
    {
        PopBack() ; 
    }
    delete m_header ; 
    delete m_trailer ; 
}

template <typename T>
void List<T>::Link(Node<T> &next_node, Node<T> &new_node, Node<T> &prev_node) 
{
    next_node.next = &new_node ; 
    new_node.prev = &next_node ; 
    new_node.next = &prev_node ; 
    prev_node.prev = &new_node ; 
}

template <typename T>
int List<T>::Size() const
{
    return m_size ; 
}

template <typename T>
bool List<T>::Empty() const 
{
    return (m_size == 0) ? true : false ;
}

template <typename T>
T &List<T>::Front() const 
{
    return m_header->next->data ; 
}

template <typename T>
T &List<T>::Back() const 
{
    return m_trailer->prev->data ; 
}

template <typename T>
void List<T>::PushFront(const T &&t) 
{
    Node<T> *new_node = new Node<T>(t) ; 
    Node<T> *prev_node = m_header->next ; 
    Link(*m_header, *new_node, *prev_node) ; 
    m_size++ ; 
}

template <typename T>
void List<T>::PushBack(const T &&t) 
{
    Node<T> *new_node = new Node<T>(t) ; 
    Node<T> *prev_node = m_trailer->prev ; 
    Link(*prev_node, *new_node, *m_trailer) ; 
    m_size++ ; 
}

template <typename T>
void List<T>::PopFront() 
{
    if(Empty())
    {
        return ; 
    }
    Node<T> *temp = m_header->next ; 
    m_header->next = temp->next ; 
    temp->next->prev = m_header ; 
    delete temp ; 
    m_size-- ; 
}

template <typename T>
void List<T>::PopBack() 
{
    if(Empty())
    {
        return ; 
    }
    Node<T> *temp = m_trailer->prev ; 
    m_trailer->prev = temp->prev ; 
    temp->prev->next = m_trailer ; 
    delete temp ; 
    m_size-- ; 
}

template <typename T>
void List<T>::Clear()
{
    while(!Empty())
    {
        PopBack() ; 
    }
    m_size = 0 ; 
}

template <typename T>
List<T> &List<T>::operator = (const List<T> &other) 
{
    this->m_size = other.m_size ; 
    Node<T> *temp = other.m_header->next ; 
    for(int i = 0 ; i < other.m_size ; i++) 
    {
        Node<T> *new_node = new Node<T>(temp->data) ; 
        Node<T> *prev_node = m_trailer->prev ; 
        Link(*prev_node, *new_node, *m_trailer) ; 
        temp = temp->next ; 
    }
    return *this ; 
}






