#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void countFreq(int arr[], int n) {
    vector<bool> visited(n, false);
    int maxFreq = INT_MIN;   //not INT_MAX for max
    vector<int> maxFreqEle;
 
    int minFreq = INT_MAX; //not INT_MIN for min
    vector<int> minFreqEle;

    for (size_t i = 0; i < n; i++) {
        if (visited[i]==true) {
            continue;
        }
         
        int count = 1;

        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j] && !visited[j]) {
                visited[j] = true;
                count++;
            }
        }
        cout << arr[i] << " :" << count << endl;

        if (count > maxFreq) {
            maxFreq = count;
            maxFreqEle.clear();
            maxFreqEle.push_back(arr[i]);
        } else if (count == maxFreq) {
            maxFreqEle.push_back(arr[i]);
        }

        if (count < minFreq) {
            minFreq = count;
            minFreqEle.clear();
            minFreqEle.push_back(arr[i]);
        } else if (count == minFreq) {
            minFreqEle.push_back(arr[i]);
        }
    }

    cout << "Maximum frequency element(s): ";
    for (auto it : maxFreqEle) {
        cout << it << " ";
    }
    cout << "with frequency " << maxFreq << endl;

    cout << "Minimum frequency element(s): ";
    for (auto it : minFreqEle) {
        cout << it << " ";
    }
    cout << "with frequency " << minFreq << endl;
}

int main() {
    int arr[] = {1, 2, 3, 3, 3, 4, 5, 6, 7, 7, 7, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    countFreq(arr, n);
    return 0;
}

/*
1 :1
2 :1
3 :3
4 :1
5 :1
6 :1
7 :3
0 :1
Maximum frequency element(s): 3 7 with frequency 3
Minimum frequency element(s): 1 2 4 5 6 0 with frequency 1
*/
