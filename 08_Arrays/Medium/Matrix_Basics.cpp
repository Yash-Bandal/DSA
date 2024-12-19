//Basic operations
#include <iostream>
#include <vector>
#include <algorithm> // For std::reverse
using namespace std;

// Function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to print a specific row
void printRow(const vector<vector<int>>& matrix, int row) {
    cout << "Row " << row + 1 << ": ";
    for (int j = 0; j < matrix[row].size(); ++j) {
        cout << matrix[row][j] << " ";
    }
    cout << endl;
}

// Function to print a specific column
void printColumn(const vector<vector<int>>& matrix, int col) {
    cout << "Column " << col + 1 << ": ";
    for (int i = 0; i < matrix.size(); ++i) {
        cout << matrix[i][col] << " ";
    }
    cout << endl;
}

// Function to reverse a specific row
void reverseRow(vector<vector<int>>& matrix, int row) {
    reverse(matrix[row].begin(), matrix[row].end());
}

// Function to transpose the matrix (swap rows with columns)
vector<vector<int>> transposeMatrix(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> transposed(cols, vector<int>(rows));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j]; // Swap rows and columns
        }
    }
    return transposed;
}

// Function to sum all elements of the matrix
int sumMatrix(const vector<vector<int>>& matrix) {
    int totalSum = 0;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            totalSum += matrix[i][j];
        }
    }
    return totalSum;
}

int main() {
    // Initialize a 2D matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);
    // Example Matrix:
    // 1  2  3
    // 4  5  6
    // 7  8  9

    // Print a specific row (Example: Row 2)
    int rowToPrint = 1; // 0-based index
    printRow(matrix, rowToPrint);
    // Example Row 2 Output: 4 5 6

    // Print a specific column (Example: Column 3)
    int columnToPrint = 2; // 0-based index
    printColumn(matrix, columnToPrint);
    // Example Column 3 Output: 3 6 9

    // Reverse a specific row (Example: Row 2)
    cout << "\nMatrix after reversing row 2:" << endl;
    reverseRow(matrix, rowToPrint);
    printMatrix(matrix);
    // Matrix After Reversing Row 2:
    // 1  2  3
    // 6  5  4
    // 7  8  9

    // Transpose the matrix (swap rows and columns)
    cout << "\nTransposed Matrix:" << endl;
    vector<vector<int>> transposedMatrix = transposeMatrix(matrix);
    printMatrix(transposedMatrix);
    // Transposed Matrix Output:
    // 1  6  7
    // 2  5  8
    // 3  4  9

    // Sum all elements in the matrix
    int totalSum = sumMatrix(matrix);
    cout << "\nSum of all elements in the original matrix: " << totalSum << endl;
    // Example Sum Output: 45 (1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9)

    return 0;
}

//////////////////////////////////////////////////////////////for loop 2
#include <iostream>
#include <vector>
#include <algorithm> // For std::reverse
using namespace std;

// Function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

// Function to print a specific row
void printRow(const vector<vector<int>>& matrix, int row) {
    cout << "Row " << row + 1 << ": ";
    for (int num : matrix[row]) {
        cout << num << " ";
    }
    cout << endl;
}

// Function to print a specific column
void printColumn(const vector<vector<int>>& matrix, int col) {
    cout << "Column " << col + 1 << ": ";
    for (int i = 0; i < matrix.size(); ++i) {
        cout << matrix[i][col] << " ";
    }
    cout << endl;
}

// Function to reverse a specific row
void reverseRow(vector<vector<int>>& matrix, int row) {
    reverse(matrix[row].begin(), matrix[row].end());
}

// Function to transpose the matrix (swap rows with columns)
vector<vector<int>> transposeMatrix(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> transposed(cols, vector<int>(rows));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j]; // Swap rows and columns
        }
    }
    return transposed;
}

// Function to sum all elements of the matrix
int sumMatrix(const vector<vector<int>>& matrix) {
    int totalSum = 0;
    for (const auto& row : matrix) {
        for (int num : row) {
            totalSum += num;
        }
    }
    return totalSum;
}

int main() {
    // Initialize a 2D matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);
    // Example Matrix:
    // 1  2  3
    // 4  5  6
    // 7  8  9

    // Print a specific row (Example: Row 2)
    int rowToPrint = 1; // 0-based index
    printRow(matrix, rowToPrint);
    // Example Row 2 Output: 4 5 6

    // Print a specific column (Example: Column 3)
    int columnToPrint = 2; // 0-based index
    printColumn(matrix, columnToPrint);
    // Example Column 3 Output: 3 6 9

    // Reverse a specific row (Example: Row 2)
    cout << "\nMatrix after reversing row 2:" << endl;
    reverseRow(matrix, rowToPrint);
    printMatrix(matrix);
    // Matrix After Reversing Row 2:
    // 1  2  3
    // 6  5  4
    // 7  8  9

    // Transpose the matrix (swap rows and columns)
    cout << "\nTransposed Matrix:" << endl;
    vector<vector<int>> transposedMatrix = transposeMatrix(matrix);
    printMatrix(transposedMatrix);
    // Transposed Matrix Output:
    // 1  6  7
    // 2  5  8
    // 3  4  9

    // Sum all elements in the matrix
    int totalSum = sumMatrix(matrix);
    cout << "\nSum of all elements in the original matrix: " << totalSum << endl;
    // Example Sum Output: 45 (1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9)

    return 0;
}

.///////////////////////////////////////////////////////////////////
//DSA
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

// 1. Boundary Traversal
// Example Matrix:
// 1  2  3
// 4  5  6
// 7  8  9
// Boundary Traversal Output: 1 2 3 6 9 8 7 4
void boundaryTraversal(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    // Top row
    for (int i = 0; i < cols; ++i) cout << matrix[0][i] << " ";
    // Right column
    for (int i = 1; i < rows; ++i) cout << matrix[i][cols - 1] << " ";
    // Bottom row (if more than 1 row)
    if (rows > 1) {
        for (int i = cols - 2; i >= 0; --i) cout << matrix[rows - 1][i] << " ";
    }
    // Left column (if more than 1 column)
    if (cols > 1) {
        for (int i = rows - 2; i > 0; --i) cout << matrix[i][0] << " ";
    }
    cout << endl;
}

// 2. Diagonal Traversal
// Example Matrix:
// 1  2  3
// 4  5  6
// 7  8  9
// Primary Diagonal Output: 1 5 9
// Secondary Diagonal Output: 3 5 7
void diagonalTraversal(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    // Top-left to bottom-right diagonal
    cout << "Primary Diagonal: ";
    for (int i = 0; i < min(rows, cols); ++i) {
        cout << matrix[i][i] << " ";
    }
    cout << endl;

    // Top-right to bottom-left diagonal
    cout << "Secondary Diagonal: ";
    for (int i = 0; i < min(rows, cols); ++i) {
        cout << matrix[i][cols - 1 - i] << " ";
    }
    cout << endl;
}

// 3. Rotate Matrix by 90 degrees (clockwise)
// Example Matrix Before Rotation:
// 1  2  3
// 4  5  6
// 7  8  9
// Matrix After 90-degree Rotation:
// 7  4  1
// 8  5  2
// 9  6  3
void rotateMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Transpose the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row
    for (int i = 0; i < n; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// 4. Maximum Submatrix Sum (Kadane's 2D Algorithm)
// Example Matrix:
// 1  2 -1
// -3 4  5
// 2  3  6
// Maximum Submatrix Sum Output: 20 (submatrix formed by [4, 5], [3, 6])
int maxSubmatrixSum(const vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    int maxSum = INT_MIN;

    // Temporary array to store row-wise sum
    for (int left = 0; left < cols; ++left) {
        vector<int> temp(rows, 0);
        for (int right = left; right < cols; ++right) {
            // Summing up columns for each row
            for (int i = 0; i < rows; ++i) {
                temp[i] += matrix[i][right];
            }

            // Now apply Kadane's Algorithm on this temp array
            int sum = 0, currentMax = INT_MIN;
            for (int val : temp) {
                sum = max(val, sum + val);
                currentMax = max(currentMax, sum);
            }
            maxSum = max(maxSum, currentMax);
        }
    }

    return maxSum;
}

// 5. Search in a Sorted Matrix (Matrix is row and column wise sorted)
// Example Matrix (Sorted):
// 1  3  5
// 7  9 11
// 13 15 17
// Searching for 9 Output: Found
bool searchInSortedMatrix(const vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Start from the top-right corner
    int i = 0, j = cols - 1;
    while (i < rows && j >= 0) {
        if (matrix[i][j] == target) return true;
        else if (matrix[i][j] > target) j--;
        else i++;
    }
    return false;
}

// 6. Spiral Traversal of Matrix
// Example Matrix:
// 1  2  3
// 4  5  6
// 7  8  9
// Spiral Traversal Output: 1 2 3 6 9 8 7 4 5
void spiralTraversal(const vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {
        // Traverse from left to right
        for (int i = left; i <= right; ++i) cout << matrix[top][i] << " ";
        top++;

        // Traverse downwards
        for (int i = top; i <= bottom; ++i) cout << matrix[i][right] << " ";
        right--;

        // Traverse from right to left
        if (top <= bottom) {
            for (int i = right; i >= left; --i) cout << matrix[bottom][i] << " ";
            bottom--;
        }

        // Traverse upwards
        if (left <= right) {
            for (int i = bottom; i >= top; --i) cout << matrix[i][left] << " ";
            left++;
        }
    }
    cout << endl;
}

// 7. Check if the matrix is symmetric
// Example Matrix:
// 1  2  3
// 2  5  6
// 3  6  9
// Symmetric Output: Yes
bool isSymmetric(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    if (rows != matrix[0].size()) return false; // Not a square matrix

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < i; ++j) {
            if (matrix[i][j] != matrix[j][i]) return false;
        }
    }
    return true;
}

int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    // 1. Boundary Traversal
    cout << "\nBoundary Traversal:" << endl;
    boundaryTraversal(matrix);

    // 2. Diagonal Traversal
    cout << "\nDiagonal Traversal:" << endl;
    diagonalTraversal(matrix);

    // 3. Rotate the matrix by 90 degrees clockwise
    rotateMatrix(matrix);
    cout << "\nMatrix after 90-degree rotation:" << endl;
    printMatrix(matrix);

    // 4. Maximum Submatrix Sum
    cout << "\nMaximum Submatrix Sum: " << maxSubmatrixSum(matrix) << endl;

    // 5. Search in a sorted matrix
    int target = 5;
    bool found = searchInSortedMatrix(matrix, target);
    cout << "\nSearching for " << target << ": " << (found ? "Found" : "Not Found") << endl;

    // 6. Spiral Traversal
    cout << "\nSpiral Traversal:" << endl;
    spiralTraversal(matrix);

    // 7. Check if matrix is symmetric
    bool symmetric = isSymmetric(matrix);
    cout << "\nIs the matrix symmetric? " << (symmetric ? "Yes" : "No") << endl;

    return 0;
}
