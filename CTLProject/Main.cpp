#include <iostream>
#include "List.h"
#include <string>

int main()
{
    {
        List<int> l1(3, 100) ; 
        List<int> l2(l1) ; 
    }
    _CrtDumpMemoryLeaks() ;
    return 0 ; 
}

