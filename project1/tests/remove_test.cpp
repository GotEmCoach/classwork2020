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

    if(!list.remove(5))
    {
        cout << "[-->] remove() failed when it should not have\n";
        exit(points);
    }
    else
    {
        if(0 != list.getFront())
        {
            cout << "[-->] remove() should not change the head of the list if we are nto removing the front\n";
            exit(points);
        }
        if(SZ-1 != list.getBack())
        {
            cout << "[-->] remove() should not change the back of the list if we are nto removing the back\n";
            exit(points);
        }
    }

    if(!list.remove(77))
    {
        cout << "[-->] remove() failed when it should not have\n";
        exit(points);
    }
    else
    {
        if(0 != list.getFront())
        {
            cout << "[-->] remove() should not change the head of the list if we are nto removing the front\n";
            exit(points);
        }
        if(SZ-1 != list.getBack())
        {
            cout << "[-->] remove() should not change the back of the list if we are nto removing the back\n";
            exit(points);
        }
    }

    if(!list.remove(0))
    {
        cout << "[-->] remove() failed when removing the front of the list\n";
        exit(points);
    }
    else
    {
        if(1 != list.getFront())
        {
            cout << "[-->] The wrong value is at the front of the list after removing the front\n";
            exit(points);
        }
        if(SZ-1 != list.getBack())
        {
            cout << "[-->] remove() should not change the back of the list if we are nto removing the back\n";
            exit(points);
        }
    }

    if(!list.remove(SZ-1))
    {
        cout << "[-->] remove() failed when removing the back of the list\n";
        exit(points);
    }
    else
    {
        if(1 != list.getFront())
        {
            cout << "[-->] The wrong value is at the front of the list \n";
            exit(points);
        }
        if(SZ-2 != list.getBack())
        {
            cout << "[-->] The wrong value is at the back of the list\n";
            exit(points);
        }
    }

    if(list.remove(999999))
    {
        cout <<"[-->] removing a value that does not exist in the list should fail\n";
        exit(points);
    }

    cout << "[-->] Test passed!\n";
    exit(MAX_POINTS);
}
