
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

//Variation 1..return element at a given row and col

#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int pascalTriangle(int r, int c) {
    int element = nCr(r - 1, c - 1);
    return element;
}

int main()
{
    int r = 5; // row number
    int c = 3; // col number
    int element = pascalTriangle(r, c);
    cout << "The element at position (r,c) is: "
            << element << "n";
    return 0;
}
        
        
