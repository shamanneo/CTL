#pragma once

template <typename T>
struct Node
{
    T data ;
    Node<T> *next ; 
    Node<T> *prev ; 

    Node() ;
    Node(T &t) ; 
} ;

template <typename T>
Node<T>::Node()
{
    next = nullptr ; 
    prev = nullptr ; 
}

template <typename T>
Node<T>::Node(T &t)
{
    data = t ; 
    next = nullptr ; 
    prev = nullptr ; 
}