#include <iostream>
#include "List.h"
#include <string>

int main()
{
    {
        List<int> l1(3, 100) ; 
        List<int> l2(l1) ; 
        List<int> l3 ; 
        l3 = l2 ; 
    }
    _CrtDumpMemoryLeaks() ;
    return 0 ; 
}

