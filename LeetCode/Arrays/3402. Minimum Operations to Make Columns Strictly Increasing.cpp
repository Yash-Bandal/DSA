class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int sum, operations = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m - 1; i++) {
                int curr = grid[i][j];
                int next = grid[i + 1][j];

                if (curr >= next) {
                    sum = curr - next + 1;
                    operations += sum; // cant return sum..as it gets updated
                                       // every time for new var..thus use
                                       // operations var  to store sum
                    grid[i + 1][j] = curr + 1; // dont update next..update in place the value
                                               // of grid..updating next=curr+1..will just
                                            // update locally..not the grid
                }
            }
        }
        return operations;
    }
};
//=======================================================================================

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int sum, operations = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int col = 0; col < n; col++) {
            for (int row = 1; row < m; row++) {
                int prev = grid[row][col];
                grid[row][col] = max(grid[row-1][col] + 1, grid[row][col]);
                operations += grid[row][col] - prev;
            }
        }
        return operations;
    }
};
