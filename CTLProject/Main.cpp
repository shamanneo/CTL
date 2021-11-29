#include <iostream>
#include "Queue.h" 
#include "List.h"

int main()
{
    {
        Queue<int> s1 ; 
        s1.Push(10) ; 
        s1.Push(20) ; 
        s1.Push(30) ; 
        s1.Push(40) ; 
        s1.Push(50) ; 

        s1.Pop() ; 
        s1.Pop() ; 
        s1.Pop() ; 

        int i = s1.Top() ; 

    }
    _CrtDumpMemoryLeaks() ;
    return 0 ; 
}

