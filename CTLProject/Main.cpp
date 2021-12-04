#include <iostream>
#include "Deque.h"
#include <list>

int main()
{
    {
        std::list<int> l1 ; 
        l1.push_back(1) ; 
        l1.push_back(2) ; 
        l1.push_back(3) ; 
        std::list<int>::iterator it ; 
        it = l1.begin() ; 
        
        int i1 = *it ; 
        *it = 444 ; 
    }
    _CrtDumpMemoryLeaks() ;
    return 0 ; 
}

