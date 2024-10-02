
//Leet
class Solution {
private:
    vector<int> generateRow(int row) {
        int ans=1;//every element
        vector<int> ansRow;
        // Push initial 1 ..each row has 1 first
        ansRow.push_back(1);

        // run from 1 to  row size  for each col
        for (int col = 1; col < row; col++) {
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }

        return ansRow;
    }

public:
    vector<vector<int>> generate(int numRows) {
        // cretae result ans 2d vec
        vector<vector<int>> res;
        for (int row = 1; row <= numRows; row++){
            res.push_back(generateRow(row));
        }
        return res;
    }
};
