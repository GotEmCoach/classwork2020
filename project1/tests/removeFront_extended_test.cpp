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
   
    for(x=0;x<SZ;x++)
    {
        i = list.getFront();
        y = list.getBack();
        if(y != SZ-1)
        {
            cout << "[-->] The back of the list should not change when removing from the front\n";
            exit(points);
        }
        if(x != i)
        {
            cout << "[-->] Expected " << x <<" but got " << i << endl;
            cout << "[-->] Test failed\n";
            exit(points);
        }
        list.removeFront();
    }

    cout << "[-->] Test passed!\n";
    exit(MAX_POINTS);
}
