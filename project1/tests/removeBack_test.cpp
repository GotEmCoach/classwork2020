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
        if(x != i)
        {
            cout << "[-->] expected " << x << " but got " << i << endl;
            exit(points);
        }

        list.removeBack();
    }


    cout << "[-->] Test passed!\n";
    exit(MAX_POINTS);
}
