#include "pq.hpp"
#include <cstdlib>

using namespace std;
#define SZ 100
#define MAX_POINTS 5

int main()
{
    PQ<int> pq;
    int i, x;
    int points = 0;

    x = pq.get_count();
    if(x!= 0)
    {
        cout << "[-->] Queue size should be 0\n";
        cout << "[-->] Test failed\n";
        exit(points);   
    }
    points+=2;

    for(i=0;i<SZ;i++)
    {
        pq.enqueue(i, i);
    }

    x = pq.get_count();
    if(x!= SZ)
    {
        cout << "[-->] Queue size should be "<<SZ<<endl;
        cout << "[-->] Test failed\n";
        exit(points);   
    }

    cout << "[-->] Test passed!\n";
    exit(MAX_POINTS);
}
