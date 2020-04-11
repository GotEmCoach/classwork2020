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

    if(!pq.isEmpty())
    {
        cout << "[-->] Queue should be empty but it reports its not\n";
        cout << "[-->] Test failed\n";
        exit(points);
    }
    points+=2;

    for(i=0;i<SZ;i++)
    {
        pq.enqueue(i, i);
    }

    if(pq.isEmpty())
    {
        cout << "[-->] Queue should have data but it says its empty\n";
        cout << "[-->] Test failed\n";
        exit(points);
    }
    points+=2;

    pq.clear();

    if(!pq.isEmpty())
    {
        cout << "[-->] Queue should be empty but it reports its not\n";
        cout << "[-->] Test failed\n";
        exit(points);
    }
    points+=2;

    cout << "[-->] Test passed!\n";
    exit(MAX_POINTS);
}
