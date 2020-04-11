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
        list.prepend(i);
        x = list.getFront();
        if(x != i)
        {
            cout << "[-->] Expected " << i << " but got " << x << endl;
            cout << "[-->] Test failed\n";
            exit(points);
        }
    }
    cout << "[-->] Test passed!\n";
    exit(MAX_POINTS);
}
