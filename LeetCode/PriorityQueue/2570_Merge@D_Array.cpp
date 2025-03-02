class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& n1,
                                    vector<vector<int>>& n2) {
        vector<vector<int>> v;
        int i = 0;
        int j = 0;

        while (i < n1.size() || j < n2.size()) {
            if (i < n1.size() && j < n2.size() && n1[i][0] == n2[j][0]) {
                v.push_back({n1[i][0], (n1[i][1] + n2[j][1])});
                i++;
                j++;
            } else if (j == n2.size() || i < n1.size() && n1[i][0] < n2[j][0]) {
                v.push_back(n1[i]);
                i++;
            } else {
                v.push_back(n2[j]);
                j++;
            }
        }
        return v;
    }
};
//use || and not && in while bcoz Then, as soon as one array is fully traversed, the loop stops, even if the other array still has elements.
// This means some elements would be missing from the result.

//n[i /j] = {whole pair}
//n[i][0 / 1] = value inside pair 


class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& n1, vector<vector<int>>& n2) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Insert all elements from n1
        for (auto& p : n1) {
            pq.push({p[0], p[1]});
        }

        // Insert all elements from n2
        for (auto& p : n2) {
            pq.push({p[0], p[1]});
        }

        vector<vector<int>> result;
        
        while (!pq.empty()) {
            auto [id, value] = pq.top();
            pq.pop();
            
            // Merge consecutive elements with the same key
            while (!pq.empty() && pq.top().first == id) {
                value += pq.top().second;
                pq.pop();
            }
            
            result.push_back({id, value});
        }

        return result;
    }
};
/*
nums1 = [[1,2],[2,3],[4,5]],
nums2 = [[1,4],[3,2],[4,1]]

p1 before merge
[{1,2} , {1,4} , {2,3} , {3,2} , {4,5} , {4,1}]

like double for loop i j ..use double while loop 
and add in result the required summed value

res =  [[1,6],[2,3],[3,2],[4,6]]
*/
