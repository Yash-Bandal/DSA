//Passing array


#include <bits/stdc++.h>
#include <climits>
using namespace std;

void countFreq(int arr[], int n)
{
    unordered_map<int, int> mpp;

    int maxFreq = INT_MIN; // not INT_MAX for max
    vector<int> maxFreqEle;

    int minFreq = INT_MAX; // not INT_MIN for min
    vector<int> minFreqEle;

    for (size_t i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    for (auto it : mpp)
    {
        cout << it.first << " :" << it.second << endl;
    }

    for (auto it : mpp)
    {
        // Max Freq
        if (it.second > maxFreq)
        {
            maxFreq = it.second;
            maxFreqEle.clear();
            maxFreqEle.push_back(it.first);
        }
        else if (it.second == maxFreq)
        {
            maxFreqEle.push_back(it.first);
        }
        
        // min freq
        if (it.second < minFreq)
        {
            minFreq = it.second;
            minFreqEle.clear();  //each time freq compared and other small freq eles are removed
            minFreqEle.push_back(it.first);  //3
        }
        else if (it.second == minFreq)
        {
            minFreqEle.push_back(it.first);  //7
        }
        /*ighth element (7, 3):

       it.second (3) == maxFreq (3) that is freq 3 is compared with 3 ..so 3 and 7 both added
       7 is added to maxFreqEle*/
    }

    cout << "Element with max Freq is: ";
    for (auto it : maxFreqEle)
    {
        cout << it << " ";
    }
    cout << "with freq " << maxFreq << endl;

    cout << "Element with min Freq is: ";
    for (auto it : minFreqEle)
    {
        cout << it << " ";
    }
    cout << "with freq " << minFreq << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 3, 3, 4, 5, 6, 7, 7, 7, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    countFreq(arr, n);
    return 0;
}



// Passing a vector
#include <bits/stdc++.h>
#include <climits>
using namespace std;

void countFreq(vector<int> vec, int n)
{
    unordered_map<int, int> mpp;

    int maxFreq = INT_MIN; // not INT_MAX for max
    vector<int> maxFreqEle;

    int minFreq = INT_MAX; // not INT_MIN for min
    vector<int> minFreqEle;

    for (size_t i = 0; i < n; i++)
    {
        mpp[vec[i]]++;
    }

    for (auto it : mpp)
    {
        cout << it.first << " :" << it.second << endl;
    }
    for (auto it : mpp)
    {
        maxFreq = max(maxFreq, it.second);
        minFreq = min(minFreq, it.second);
    }
    for (auto it : mpp)
    {
        if (it.second == maxFreq)
            maxFreqEle.push_back(it.first);

        if (it.second == minFreq)
            minFreqEle.push_back(it.first);
    }

    cout << "Element with max Freq is: ";
    for (auto it : maxFreqEle)
    {
        cout << it << " ";
    }
    cout << "with freq " << maxFreq << endl;

    cout << "Element with min Freq is: ";
    for (auto it : minFreqEle)
    {
        cout << it << " ";
    }
    cout << "with freq " << minFreq << endl;
}

int main()
{
    vector<int> vec = {1, 2, 3, 3, 3, 4, 5, 6, 7, 7, 7, 0};
    int n = vec.size();
    countFreq(vec, n);
    return 0;
}

