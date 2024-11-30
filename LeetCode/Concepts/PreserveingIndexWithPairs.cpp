//leet 506


/* 
How most pair datatypes are used for most questions
 
An array is given  and we need to perform changes in arrray preserving the index

if maxelem quest we use minHeaps prio ques with pairs

step..
declare pair
store {vectorEle,index i}
create an empty res vector

vector<string / int> res (n); res[0,0,0,0,0,0]

declare pair.first as value and pair.second as index

place using while loop res[ind / pair.second] = value

return

-------------------------------------------------------------

*/
class Solution { // result is string
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size(); // n = 5 for the input [10, 3, 8, 9, 4]
        priority_queue<pair<int, int>> pq; // Max-heap to store scores with their indices

        // Store index and score in the max-heap
        for (int i = 0; i < n; i++) {
            pq.push({score[i], i}); // Adding pairs: {(10, 0), (3, 1), (8, 2), (9, 3), (4, 4)}
        }

        vector<string> res(n); // Initialize result vector: res = ["", "", "", "", ""]
        int rank = 1; // Initialize rank

        while (!pq.empty()) {
            pair<int, int> maxEle = pq.top(); // Get the pair with the max score and index
            // Example in first iteration: maxEle = {10, 0} (score 10 at index 0)
            pq.pop(); // Remove the top element from the heap
            int curr = maxEle.first; // curr = 10 (current max score)
            int ind = maxEle.second; // ind = 0 (index of the max score)

            // Assign ranks based on the current rank value
            if (rank == 1) {
                res[ind] = "Gold Medal"; // Assign "Gold Medal" to index 0
                // res = ["Gold Medal", "", "", "", ""]
            } else if (rank == 2) {
                res[ind] = "Silver Medal"; // For the next iteration, assign "Silver Medal"
            } else if (rank == 3) {
                res[ind] = "Bronze Medal"; // For the next iteration, assign "Bronze Medal"
            } else {
                res[ind] = to_string(rank); // For ranks 4 and above, convert rank to string
            }
            rank++; // Increment the rank for the next athlete
        }

        // Final result after processing all scores
        // For the input [10, 3, 8, 9, 4], the final output will be:
        // res = ["Gold Medal", "5", "Bronze Medal", "Silver Medal", "4"]
        return res;
    }
};

// Final output is: ["Gold Medal", "5", "Bronze Medal", "Silver Medal", "4"]


Problem:
Given an array, we need to make certain changes to the array while preserving the original indices.

Key Idea:
To perform index-based changes, we can use a pair data type. The pair can store:

pair.first -> the value from the array.
pair.second -> the index of that value in the original array.
Pairs are especially useful when:

We need to rearrange or sort elements, but the original positions (indices) of those elements must still be known.
For example, in problems where the maximum element at any index is queried, we can use a priority queue (minHeap) to efficiently track values along with their indices.

Steps:
Declare a vector of pairs:

Each pair holds a value and its corresponding index.
Example: vector<pair<int, int>> v;
Store array elements with their indices:

Traverse the array and store {arrayElement, index} in a pair.
cpp
Copy code
for (int i = 0; i < n; i++) {
    v.push_back({arr[i], i});
}
Create an empty result vector:

This will store the final result after processing.
cpp
Copy code
vector<int> res(n, 0);  // Initialize result vector of size n with 0.
Use a priority queue (minHeap or maxHeap):

You can use a priority queue (with pairs) to get the minimum or maximum element as per the problem's requirement.
cpp
Copy code
priority_queue<pair<int, int>> pq;
for (int i = 0; i < n; i++) {
    pq.push({arr[i], i});
}
Processing using the pairs:

Use the stored pairs to perform operations on the array while preserving the indices.
For example, to replace the original array with sorted values while keeping their original indices:
cpp

while (!pq.empty()) {
    auto p = pq.top();  // Get the max element
    pq.pop();
    res[p.second] = p.first;  // Place it at the correct index
}
Return or print the result:

The res vector now contains the modified values, but their positions are preserved based on the indices.
