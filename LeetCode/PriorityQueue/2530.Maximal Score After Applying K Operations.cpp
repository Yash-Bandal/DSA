//Brute TLE
/*
Concept

adding a vector withing maxHeap
way 1:
 priority_queue<int> maxHeap(nums.begin(), nums.end());

way 2:
  priority_queue<int> pq;
     
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }


1. Initialize a max-heap
You can initialize a max-heap either by:

Empty initialization: Starting with an empty heap.
priority_queue<int> maxHeap;

Range initialization: Building the heap from an existing collection like a vector.
vector<int> nums = {5, 1, 9, 7, 3};
priority_queue<int> maxHeap(nums.begin(), nums.end());

2. Push (Insert an Element)
The push() operation adds a new element to the heap and maintains the heap property (max-heap).
maxHeap.push(10);  // Inserts the element 10 into the heap
Time Complexity: O(log n), where n is the number of elements currently in the heap.

3. Top (Access the Largest Element)
The top() operation returns the largest element in the heap (the root of the max-heap).
int maxElement = maxHeap.top();  // Returns the largest element
Time Complexity: O(1).

4. Pop (Remove the Largest Element)
The pop() operation removes the largest element (the root) from the heap and restructures the heap to maintain the max-heap property.
maxHeap.pop();  // Removes the largest element from the heap
Time Complexity: O(log n).

5. Size (Number of Elements in the Heap)
The size() operation returns the number of elements currently stored in the heap.
int heapSize = maxHeap.size();  // Returns the number of elements in the heap
Time Complexity: O(1).

6. Empty (Check if the Heap is Empty)
The empty() operation returns true if the heap is empty, and false otherwise.
bool isEmpty = maxHeap.empty();  // Returns true if the heap is empty
Time Complexity: O(1).

7. Swap (Exchange Contents of Two Heaps)
The swap() operation swaps the contents of two heaps.
priority_queue<int> heap1, heap2;
// Fill heap1 and heap2
heap1.swap(heap2);  // Exchanges the contents of heap1 and heap2
Time Complexity: O(1).


*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    // Initialize maxHeap with a vector of numbers
    vector<int> nums = {5, 1, 9, 7, 3};
    priority_queue<int> maxHeap(nums.begin(), nums.end()); // Range initialization
    
    // Push a new element into the max-heap
    maxHeap.push(10);

    // Print the largest element (top of the heap)
    cout << "The largest element: " << maxHeap.top() << endl;

    // Remove the largest element (pop operation)
    maxHeap.pop();
    cout << "After popping, the largest element: " << maxHeap.top() << endl;

    // Check the size of the heap
    cout << "Heap size: " << maxHeap.size() << endl;

    // Check if the heap is empty
    cout << "Is heap empty? " << (maxHeap.empty() ? "Yes" : "No") << endl;

    // Initialize another heap
    priority_queue<int> anotherHeap;
    anotherHeap.push(15);
    anotherHeap.push(20);

    // Swap contents of two heaps
    maxHeap.swap(anotherHeap);

    // After swap, print the largest element of the new maxHeap
    cout << "After swapping, the largest element in maxHeap: " << maxHeap.top() << endl;

    return 0;
}


---------------------------------------------------------------------------
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n=nums.size();
        long long score=0;
     while(k!=0){
         sort(nums.begin(),nums.end());
         int maxEle=nums.back();
         score+=maxEle;
         nums.back()=ceil(maxEle/3.0);
         
         k--;
     }
        return score;
        
    }
};


//PQ
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int> pq;
        long long score=0;
        
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        
        while(k--){
            int maxEle=pq.top();
            score+=maxEle;
            pq.pop();
            //dont do pq.top()=ceil(maxEle/3.0)..pq.top just acces val not update
            pq.push(ceil(maxEle/3.0)); //if not used 3.0 and used  ...we get small changed output like score 16..instead of 17..thus use 3.0
            
        }
        return score;
        
    }
};


class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        // Max heap to get the largest element efficiently
        priority_queue<int> maxHeap(nums.begin(), nums.end());
        
        long long score = 0;
        
        // Perform the operation k times
        while (k--) {
            int maxElement = maxHeap.top();
            maxHeap.pop();
            
            // Add the largest element to the score
            score += maxElement;
            
            // Push the updated value (ceil(maxElement / 3)) back into the heap
            maxHeap.push(ceil(maxElement / 3.0));
        }
        
        return score;
    }
};
