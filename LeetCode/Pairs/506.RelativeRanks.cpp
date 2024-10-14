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
