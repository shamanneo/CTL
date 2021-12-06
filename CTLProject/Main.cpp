#include <iostream>
#include <string>
#include "List.h"

using namespace std ; 
class foo
{
    private :
        int m_i ;
        string m_s ;
    public :
        foo(int i, string s) 
            : m_i(i), m_s(s)
        {

        }
} ; 

int main()
{
    {
        List<int> l1 ; 
        l1.PushBack(1) ; 
        l1.PushBack(2) ; 
        l1.PushBack(3) ; 
        l1.PushBack(4) ; 
        List<int>::Iterator it = l1.Begin() ; 
        it = l1.End() ; 

        


    }
    _CrtDumpMemoryLeaks() ;
    return 0 ; 
}

