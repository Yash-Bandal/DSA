class Solution {
private:
    // Function to mark an element and its adjacent elements as visited
    (INT_MAX) void markVisited(int i, vector<int>& visited) {
        int n = visited.size();

        // Mark the current element
        visited[i] = INT_MAX;

        // Mark the left neighbor if it exists
        if (i > 0) {
            visited[i - 1] = INT_MAX;
        }

        // Mark the right neighbor if it exists
        if (i < n - 1) {
            visited[i + 1] = INT_MAX;
        }
    }

public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long score = 0;
        vector<int> visited = nums; // Copy nums to visited

        while (true) {
            int minEle = INT_MAX;
            int minIndex = -1;

            // Find the smallest unmarked element
            for (int i = 0; i < n; ++i) {
                if (visited[i] != INT_MAX && visited[i] < minEle) {
                    minEle = visited[i];
                    minIndex = i;
                }
            }

            // If all elements are marked, break the loop
            if (minIndex == -1) {
                break;
            }

            // Add the smallest element to the score
            score += minEle;

            // Mark the element and its neighbors
            markVisited(minIndex, visited);
        }

        return score;
    }
};
// //Time Limit Exceeded
// //1036 / 1044 testcases passed

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long score = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }

        vector<bool> visited(n, false); //[f,f,f,f,f,f] initially

        while (!pq.empty()) {
              //1. Get the smallest unmarked element
            auto [value, ind] = pq.top();
            pq.pop();

          //2. skip if visited
            if (visited[ind]) {
                continue;
            }

          //3. add the smalles to score
            score += value;

          //4. Mark visited
            visited[ind] = true;
            if (ind > 0) {  //if i=0 marked true in above line
                visited[ind - 1] = true;
            }
            if (ind < n - 1) {
                visited[ind + 1] = true;  //even if i=0 marked the next ele true by this line
            }
        }
        return score;
    }
};



//=========================================DEQUE==========================================
class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0; // Change to long long to avoid overflow
        int n = nums.size();
        deque<int> q;

        // Traverse through the array
        for (int i = 0; i < n; i++) {
            // If queue is not empty and the current number is greater than or equal to the last in queue
            if (!q.empty() && nums[i] >= q.back()) {
                bool skip = false;
                // Process the elements in the queue
                while (!q.empty()) {
                    int add = q.back();
                    q.pop_back();
                    if (!skip) {
                        score += add;
                    }
                    skip = !skip;
                }
                continue;
            }

            // Add current element to the queue
            q.push_back(nums[i]);
        }

        // Final processing of remaining elements in the queue
        bool skip = false;
        while (!q.empty()) {
            int add = q.back();
            q.pop_back();
            if (!skip) {
                score += add;
            }
            skip = !skip;
        }

        return score;
    }
};
