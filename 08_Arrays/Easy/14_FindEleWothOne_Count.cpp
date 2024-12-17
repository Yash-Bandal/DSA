//Brute Force  eazy logic
#include <bits/stdc++.h>
using namespace std;

int getSingleElement(vector<int> &arr) {
    // Size of the array:
    int n = arr.size();

    //Run a loop for selecting elements:
    for (int i = 0; i < n; i++) {
        int num = arr[i]; // selected element
        int cnt = 0;  //reset to 0

        //find the occurrence using linear search:
        for (int j = 0; j < n; j++) {
            if (arr[j] == num)
                cnt++;
        }

        // if the occurrence is 1 return ans:
        if (cnt == 1) return num;
    }


    //if the array contains no single element.
    return -1;
}

int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};
  //  vector<int> arr = {4, 4 , 1, 2, 1, 2}; //try this to get -1
    int ans = getSingleElement(arr);
    cout << "The single element is: " << ans << endl;
    return 0;
}

/*
Time Complexity: O(N2), where N = size of the given array.
Reason: For every element, we are performing a linear search to count its occurrence. The linear search takes O(N) time complexity. And there are N elements in the array. So, the total time complexity will be O(N2).

Space Complexity: O(1) as we are not using any extra space.
*/


//Better Approach(Using Hashing): 

#include <bits/stdc++.h>
using namespace std;

int getSingleElement(vector<int> &arr) {

    int n = arr.size();

    // Find the maximum element: so as to declare hash array size ..here 4 is large num so we requre 4 size hash arr
    int maxi = arr[0];
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i]);
    }

    // Declare hash array of size maxi+1  ..this is mapping like adding frequencies
    // And hash the given array:
    vector<int> hash(maxi + 1, 0);  //+1 bcoz 5 values of hash 0 0 0 0 0 initial 
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    //Find the single element and return the answer:
    for (int i = 0; i < n; i++) {
        if (hash[arr[i]] == 1)
            return arr[i];
    }

    //This line will never execute
    //if the array contains a single element.
    return -1;
}

int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};
    int ans = getSingleElement(arr);
    cout << "The single element is: " << ans << endl;
    return 0;
}
/*
Explanation of the Hash Array:

1. Input Array: {4, 1, 2, 1, 2}
2. Maximum Element (`maxi`): 4

Step 1: Initialize Hash Array

- Hash Array Size: `maxi + 1 = 4 + 1 = 5`
- Initial Hash Array:
  Index:  0  1  2  3  4
  Value:  0  0  0  0  0

Step 2: Populate the Hash Array

We iterate through the input array and increment the corresponding index in the hash array.

1. First element (4):
   - Increment `hash[4]` by 1:
     Index:  0  1  2  3  4
     Value:  0  0  0  0  1

2. Second element (1):
   - Increment `hash[1]` by 1:
     Index:  0  1  2  3  4
     Value:  0  1  0  0  1

3. Third element (2):
   - Increment `hash[2]` by 1:
     Index:  0  1  2  3  4
     Value:  0  1  1  0  1

4. Fourth element (1):
   - Increment `hash[1]` by 1:
     Index:  0  1  2  3  4
     Value:  0  2  1  0  1

5. Fifth element (2):
   - Increment `hash[2]` by 1:
     Index:  0  1  2  3  4
     Value:  0  2  2  0  1

Step 3: Identify the Single Element

- Index 0: `hash[0] = 0` → No element 0 in the input array.
- Index 1: `hash[1] = 2` → The element 1 occurs twice.
- Index 2: `hash[2] = 2` → The element 2 occurs twice.
- Index 3: `hash[3] = 0` → No element 3 in the input array.
- Index 4: `hash[4] = 1` → The element 4 occurs exactly once.

Final Hash Array:
  Index:  0  1  2  3  4
  Value:  0  2  2  0  1

Conclusion:
The hash array helps in counting occurrences of each element. The size `maxi + 1` ensures that every element can be indexed properly, allowing us to find the element that appears exactly once.
*/



//Map

#include <bits/stdc++.h>
using namespace std;

int getSingleElement(vector<int> &arr) {

    //size of the array:
    int n = arr.size();

    // Declare the hashmap.
    // And hash the given array:
    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    //Find the single element and return the answer:
    for (auto it : mpp) {
        if (it.second == 1)
            return it.first;
    }

    //This line will never execute
    //if the array contains a single element.
    return -1;
}

int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};
    int ans = getSingleElement(arr);
    cout << "The single element is: " << ans << endl;
    return 0;
}
/*
Time Complexity: O(N*logM) + O(M), where M = size of the map i.e. M = (N/2)+1. N = size of the array.
Reason: We are inserting N elements in the map data structure and insertion takes logM time(where M = size of the map). So this results in the first term O(N*logM). The second term is to iterate the map and search the single element. In Java, HashMap generally takes O(1) time complexity for insertion and search. In that case, the time complexity will be O(N) + O(M).

Note: The time complexity will be changed depending on which map data structure we are using. If we use unordered_map in C++, the time complexity will be O(N) for the best and average case instead of O(N*logM). But in the worst case(which rarely happens), it will be nearly O(N2).

Space Complexity: O(M) as we are using a map data structure. Here M = size of the map i.e. M = (N/2)+1.
*/


//XOR ^



#include <bits/stdc++.h>
using namespace std;

int getSingleElement(vector<int> &arr) {
    //size of the array:
    int n = arr.size();

    // XOR all the elements:
    int xorr = 0;
    for (int i = 0; i < n; i++) {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}

int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};
    int ans = getSingleElement(arr);
    cout << "The single element is: " << ans << endl;
    return 0;
}


