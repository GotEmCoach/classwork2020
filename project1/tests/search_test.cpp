#include "dll.hpp"
#include "gtest/gtest.h"
#include <cstdlib>

using namespace std;
#define SZ 100
#define MAX_POINTS 5
int main()
{
    DLL<int> list;
    Node<int> *result;

    int i, x, y;
    int points = 0;

    for(i=0;i<SZ;i++)
    {
        list.append(i);
    }

    result = list.search(0);
    if(NULL == result)
    {
        cout << "[-->] result should not have been null\n";
        exit(points);
    }
    if(result->get_data() != 0)
    {
        cout << "[-->] expected node to hold 0 but it had " << result->get_data() << endl;
        exit(points);
    }

    result = list.search(99);
    if(NULL == result)
    {
        cout << "[-->] result should not have been null\n";
        exit(points);
    }
    if(result->get_data() != 99)
    {
        cout << "[-->] expected node to hold 99 but it had " << result->get_data() << endl;
        exit(points);
    }

    result = list.search(123456);
    if(NULL != result)
    {
        cout <<"[-->] search() should have returned NULL when the value to be searched for does not exist in the list\n";
        exit(points);
    }

    cout << "[-->] Test passed!\n";
    exit(MAX_POINTS);
}
