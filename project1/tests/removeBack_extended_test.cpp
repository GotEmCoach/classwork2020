#include "dll.hpp"
#include "gtest/gtest.h"
#include <cstdlib>

using namespace std;
#define SZ 100
#define MAX_POINTS 5
int main()
{
    DLL<int> list;
    int i, x, y;
    int points = 0;

    for(i=0;i<SZ;i++)
    {
        list.append(i);
    }

    for(x=SZ-1;x>=0;x--)
    {
        i = list.getBack();
        if(0 != list.getFront())
        {
            cout << "[-->] The front of the list should not change when the back is removed\n";
            exit(points);
        }
        if(x != i)
        {
            cout << "[-->] expected " << x << " but got " << i << endl;
            exit(points);
        }
        
        if(!list.removeBack())
        {
            cout <<"[-->] removeBack failed\n";
            exit(points);
        }
    }


    cout << "[-->] Test passed!\n";
    exit(MAX_POINTS);
}
