#include "dll.hpp"
#include "gtest/gtest.h"
#include <cstdlib>

using namespace std;
#define SZ 100
#define MAX_POINTS 5
int main()
{
    DLL<int> list;
    int i, x;
    int points = 0;

    for(i=0;i<SZ;i++)
    {
        list.append(i);
    }

    for(x=0;x<SZ;x++)
    {
        i = list.getFront();
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
