//Q1. Zigzag Grid Traversal With Skip
class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int m = grid.size();    // Number of rows
        int n = grid[0].size(); // Number of columns
        vector<int> oneD;
        vector<int> res;

        for (int row = 0; row < m; row++) {
            if (row % 2 == 0) { // Left to right for even rows
                for (int col = 0; col < n; col++) {
                    oneD.push_back(grid[row][col]);
                }
            } else { // Right to left for odd rows
                for (int col = n - 1; col >= 0; col--) {
                    oneD.push_back(grid[row][col]);
                }
            }
        }

        for (int i = 0; i < oneD.size(); i += 2) {
            res.push_back(oneD[i]);
        }
        return res;
    }
};
/*
for testcase 3
m = 3;
n = 3;

observe  col -->
            0  1  2
grid  = 0  [1, 2, 3],
 row    1  [4, 5, 6],
  |     2  [7, 8, 9]
  v

traverse left to right when index of row is even   0 2 4 ...
traverse right to left when index of row is odd    1 3 5 ...


first form a 1d array 2D-1D
oneD = [1 2 3  6 5 4  7 8 9]

then skip one by one elements and push in res array
res =  [1   3    5    7   9]


*/
