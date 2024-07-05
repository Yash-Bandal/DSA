#include <bits/stdc++.h>
#include <utility>
#include <iostream>
#include <array>
#include <algorithm> // For std::sort

using namespace std;
 bool comp(pair<int, int> p1, pair<int, int> p2)
    { // consider atleast 2 pir for comp
        if (p1.second < p2.second)
            return true;
        if (p1.second > p2.second)
            return false;

        // now the only condition remains is equality < > =  automatic in else no need o def seperate
        if (p1.first > p2.first)
            return true;
        return false;
    }
int main()
{
    // Create an std::array with some unsorted integers
    array<int, 5> myArray = {4, 1, 3, 5, 2};

    // Print the original array
    cout << "Original array: ";
    for (int num : myArray)
    {
        cout << num << " ";
    }
    cout << endl; // Output: Original array: 4 1 3 5 2

    // Sort the array
    sort(myArray.begin(), myArray.end());

    // raw array
    int arr[] = {1, 2, 3, 6, 4, 8, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + size);
    // Print the sorted array
    cout << "Sorted array  2: ";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Print the sorted array
    cout << "Sorted array: ";
    for (const int &num : myArray)
    {
        cout << num << " ";
    }
    cout << endl; // Output: Sorted array: 1 2 3 4 5


//Sorting an array in "my way" here second element sorted in ascending...if equal ele comparison...first ele of pair sorted in descending
   
    pair<int, int> arr2[] = {{2, 1}, {1, 2}, {4, 1}};
    int n = sizeof(arr2) / sizeof(arr2[0]);

    sort(arr2, arr2 + n, comp);

    cout<<"Sorted Pair array is :"<<endl;
    for(auto p : arr2)
    {
        cout<<"{"<<p.first<<","<<p.second<<"} ";
    }
    //{4,1} {2,1} {1,2}  4,2 1 descending as 1 1 equal   1 1 2 in ascending
    //if ip is  {{2, 6}, {1, 2}, {4, 1}}  ..no equal 2nd ..no descending sort {4,1} {1,2} {2,6}

    return 0;
}
