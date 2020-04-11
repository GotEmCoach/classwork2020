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

    for(i=0;i<SZ;i++)
    {
        pq.enqueue(i, i);
    }

    for(i=0;i<SZ;i++)
    {
        x = pq.get_front();
        if(x != i)
        {
            cout << "[-->] Expected " << i <<" but got " << x << endl;
            cout << "[-->] Test failed\n";  
            exit(points); 
        }
        pq.dequeue();
    }

    cout << "[-->] Test passed!\n";
    exit(MAX_POINTS);
}
