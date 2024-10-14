/* 

Easy 

Problem Setup:
You are given an array or sequence of numbers, and you need to perform some operations that require repeated access to the maximum or minimum element. This is where a priority queue (heap) comes into play.

Priority queues come in two common types:
- Min-heap (smallest element on top, which is the default behavior in C++ with std::priority_queue if using negative values or custom comparators).
- Max-heap (largest element on top, which is the default behavior in C++ with std::priority_queue).

Key Use Cases for Priority Queue:
- Finding the k-largest or k-smallest elements.
- Merging sorted arrays.
- Dynamic median finding.
- Processing tasks in order of priority.
*/

// Steps for a Priority Queue Approach:

// 1. Choose the Type of Priority Queue:

// Max-heap (default in C++): 
std::priority_queue<int> pq;  // Max-heap

// Min-heap using a custom comparator or negating the values
std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;  // Min-heap

// 2. Insert Elements into the Priority Queue:

// Push elements from the array into the priority queue. For example, for an array arr[]:
for (int i = 0; i < n; i++) {
    pq.push(arr[i]);  // Push elements into the max-heap
}

// 3. Accessing the Top Element:

// The top of the heap gives you either the maximum (for max-heap) or minimum (for min-heap) element, depending on the type of queue.
int maxElement = pq.top();  // Max element (if max-heap)

// 4. Pop Elements from the Priority Queue:

// You can remove the top element (maximum or minimum) using the pop() function.
pq.pop();  // Remove the top element

// 5. Processing Based on the Problem:
// Depending on the problem, you may need to:
// - Keep pushing and popping elements as you process them.
// - Extract the k-largest or k-smallest elements.
// - Maintain a running window of elements for dynamic operations (like finding medians, etc.).

// Example Problems:

// a) Finding the k-largest elements:

// If you need to find the k-largest elements in an array:
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;  // Min-heap
for (int i = 0; i < n; i++) {
    pq.push(arr[i]);
    if (pq.size() > k) pq.pop();  // Keep the heap size at k
}
// Now pq contains the k-largest elements

// b) Dynamic median finding:

// You can maintain two heaps:
// A max-heap for the smaller half of the numbers.
std::priority_queue<int> maxHeap;  // Max-heap for the left side

// A min-heap for the larger half of the numbers.
std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;  // Min-heap for the right side

// For each new element, insert it into one of the heaps, and balance the heaps so that their sizes remain nearly equal. 
// The top of the max-heap will give the median for an odd-sized collection.

// Complete Example: Finding the k-largest elements

#include <iostream>
#include <vector>
#include <queue>  // Priority queue library

using namespace std;

int main() {
    vector<int> arr = {10, 5, 8, 3, 7};
    int k = 3;
    
    // Min-heap to store the k-largest elements
    priority_queue<int, vector<int>, greater<int>> pq;
    
    // Push elements into the heap
    for (int i = 0; i < arr.size(); i++) {
        pq.push(arr[i]);
        
        // If the heap size exceeds k, remove the smallest element
        if (pq.size() > k) {
            pq.pop();
        }
    }
    
    // The priority queue now contains the k-largest elements
    cout << "The " << k << " largest elements are: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    
    return 0;
}

/*
Output:
The 3 largest elements are: 7 8 10
*/

// Summary of Steps:
// 1. Initialize the appropriate priority queue (max-heap or min-heap).
// 2. Push elements into the queue as needed.
// 3. Process the elements while maintaining the queue's size and integrity based on the problem.
// 4. Access and manipulate the top element to solve the problem efficiently.
// This general approach works for most priority queue-based questions.
