class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {

        priority_queue<int> distances;
        vector<int> result;

        for (auto& query : queries) {
            int x = query[0];
            int y = query[1];
            // first we need manhatten distance from orig
            int distance = abs(x) + abs(y);

          //  distances.push_back(distance);
            // sort dist to get minimum one ahead

            //  sort(distances.begin(), distances.end()); giving TLE for vector
            //  so use prio queue
            if (distances.size() < k) {
                distances.push(distance);
            } else if (distance < distances.top()) {
                distances.pop();
                distances.push(distance);
            }

            // check if we have at least k obstacles
            if (distances.size() < k) {
                result.push_back(-1);
            } else {
                result.push_back(distances.top());
            }
        }
        return result;
    }
};
