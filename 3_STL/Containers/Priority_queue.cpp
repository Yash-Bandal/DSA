#include<bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
void printpq(priority_queue<int> pq)
// void printpq(priority_queue<int , vector<int> ,greater<int>> pq)
{
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main() {
    priority_queue<int> pq;    //max-heap pq  //20 15 10 
    // priority_queue<int , vector<int> ,greater<int>> pq;  //min-heap pq // 10 15 20 

    pq.push(10);
    pq.push(20);
    pq.push(15);

    cout << "Max-Heap elements: ";
    printpq(pq);

    return 0;
}
