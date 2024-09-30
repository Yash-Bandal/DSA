class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m=matrix[0].size();   //dont forget this
        
        // Check if the matrix is empty
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }

        int left = 0;       // col
        int right = m - 1;  // col
        int top = 0;        // row
        int bottom = n - 1; // row

        vector<int> res;

        while (top <= bottom && left <= right) {
            // for 1
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;

            // for 2
            for (int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;
            if (top <= bottom) {   //dont forget this if statesments
                // for 3
                for (int i = right; i >= left; i--) {
                    res.push_back(matrix[bottom][i]);  //--loops
                }
                bottom--;
            }
            // for 4
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {   //-- loops
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};
