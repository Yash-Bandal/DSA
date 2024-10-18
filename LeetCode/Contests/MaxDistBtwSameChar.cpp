
#include <bits/stdc++.h>
using namespace std;

int maxDistanceBruteForce(const string& s) {
    int maxDistance = -1;  // Initialize to -1 to handle cases with no matching characters.
    
    // Loop over all possible pairs of indices.
    for (int i = 0; i < s.length(); ++i) {
        for (int j = i + 1; j < s.length(); ++j) {
            if (s[i] == s[j]) {
                int distance = j - i - 1;  // Distance between two same characters, excluding them.
                maxDistance = max(maxDistance, distance);
            }
        }
    }
    
    return maxDistance;
}

int main() {
    string input;
    cin >> input;
    
    int result = maxDistanceBruteForce(input);
    
    if (result == -1) {
        cout << "No two same characters found!" << endl;
    } else {
        cout << "Maximum number of characters between two same characters: " << result << endl;
    }

    return 0;
}
