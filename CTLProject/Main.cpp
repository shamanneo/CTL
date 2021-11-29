#include <iostream>
#include "Stack.h"
#include "List.h"

int main()
{
    {
        Stack<int> s1 ; 
        s1.Push(10) ; 
        s1.Push(20) ; 
        s1.Push(30) ; 
        s1.Push(40) ; 
        s1.Push(50) ; 

        s1.Pop() ; 
        s1.Pop() ; 
        s1.Pop() ; 

        int i = s1.Top() ; 

        Stack<int> s2(s1) ; 
        Stack<int> s3 ; 
        s3 = s2 ; 
    }
    _CrtDumpMemoryLeaks() ;
    return 0 ; 
}

