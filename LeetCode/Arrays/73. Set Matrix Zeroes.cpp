
//-10 is just temporary number..dont use -1 as 1 testcase has that num
class Solution {
private:

    void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
        for(int j=0;j<m;j++){
            if(matrix[i][j] != 0){
                matrix[i][j] =-10;
            }
        }
    }

    void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
         for(int i=0;i<n;i++){
            if(matrix[i][j] != 0){
                matrix[i][j] =-10;
            }
        }
    }

public:
    void setZeroes(vector<vector<int>>& matrix) {
       int n=matrix.size();
       int m=matrix[0].size();
        // traverse matrix and mark -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    markRow(matrix,n,m,i);
                    markCol(matrix,n,m,j);
                }
            }
        }
        // mark -1 to 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == -10) {

                    matrix[i][j] = 0;
                }
            }
        }
    }
};
