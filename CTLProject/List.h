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
        explicit List(int size = 0) ;
        List(int size, T &&t) ; 
        List(const List<T> &l) ; 
        ~List() ; 
    public :
        int Size() const ;
        bool Empty() const ; 
        T &Front() const ; 
        T &Back() const ;
        void PushFront(T &&t) ; 
        void PushBack(T &&t) ; 
        void PopFront() ; 
        void PopBack() ; 
        List &operator = (const List<T> &l) ; 
} ; 

template <typename T>
List<T>::List(int size)
    : m_size(size), m_header(new Node<T>), m_trailer(new Node<T>) 
{
    m_header->next = m_trailer ; 
    m_trailer->prev = m_header ; 
}

template <typename T>
List<T>::List(int size, T &&t)
    : List(size)
{
    for(int i = 0 ; i < size ; i++)
    {
        Node<T> *new_node = new Node<T>(t) ; 
        Node<T> *prev_node = m_trailer->prev ; 
        Link(*prev_node, *new_node, *m_trailer) ; 
    }
}

template <typename T>
List<T>::List(const List<T> &l)
    : List(l.m_size) 
{   
    *this = l ; 
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
void List<T>::PushFront(T &&t) 
{
    Node<T> *new_node = new Node<T>(t) ; 
    Node<T> *prev_node = m_header->next ; 
    Link(*m_header, *new_node, *prev_node) ; 
    m_size++ ; 
}

template <typename T>
void List<T>::PushBack(T &&t) 
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
List<T> &List<T>::operator = (const List<T> &l) 
{
    this->m_size = l.m_size ; 
    Node<T> *temp = l.m_header->next ; 
    for(int i = 0 ; i < l.m_size ; i++) 
    {
        Node<T> *new_node = new Node<T>(temp->data) ; 
        Node<T> *prev_node = m_trailer->prev ; 
        Link(*prev_node, *new_node, *m_trailer) ; 
        temp = temp->next ; 
    }
    return *this ; 
}
