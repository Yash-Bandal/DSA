//Map
#include <bits/stdc++.h>
using namespace std;

vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  map < int, int > freq;
  vector < int > Union;
  //Iterate through first and store the element in map..
  for (int i = 0; i < n; i++) 
    freq[arr1[i]]++;

  //second arr
  for (int i = 0; i < m; i++)
    freq[arr2[i]]++;

  //push the keys in union vector as we are not  returning map here
  for (auto & it: freq)
    Union.push_back(it.first);
  return Union;
}

int main() {
  int n = 10, m = 7;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4, 5, 11, 12};
  vector < int > Union = FindUnion(arr1, arr2, n, m);
  cout << "Union of arr1 and arr2 is " << endl;
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}
/*
return this it.first
Key (Element)	Value (Frequency)
1             	1
2	              2
3	              2
4	              3
5	              2
6	              1
7	              1
8	              1
9	              1
10	            1
11	            1
12	            1
*/


//Sets  set stores uniq
#include <bits/stdc++.h>
using namespace std;

vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  set < int > s;
  vector < int > Union;
  for (int i = 0; i < n; i++)
    s.insert(arr1[i])
      
  for (int i = 0; i < m; i++)
    s.insert(arr2[i]);
  
  for (auto & it: s)
    Union.push_back(it);
  return Union;
}

int main()
{
  int n = 10, m = 7;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4, 5, 11, 12};
  vector < int > Union = FindUnion(arr1, arr2, n, m);
  cout << "Union of arr1 and arr2 is  " << endl;
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}

//Two pointers
#include <bits/stdc++.h>

using namespace std;

vector<int> FindUnion(int arr1[], int arr2[], int n, int m) {
    int i = 0, j = 0; // pointers
    vector<int> Union; // Union vector

    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) // Case 1 and 2
        {
            if (Union.size() == 0 || Union.back() != arr1[i])
                Union.push_back(arr1[i]);
            i++;
        } else // case 3
        {
            if (Union.size() == 0 || Union.back() != arr2[j])
                Union.push_back(arr2[j]);
            j++;
        }
    }
    
    while (i < n) // If any element left in arr1
    {
        if (Union.back() != arr1[i])
            Union.push_back(arr1[i]);
        i++;
    }
    
    while (j < m) // If any element left in arr2
    {
        if (Union.back() != arr2[j])
            Union.push_back(arr2[j]);
        j++;
    }
    
    return Union;
}

int main() {
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {2, 3, 4, 4, 5, 6}; 
    vector<int> Union = FindUnion(arr1, arr2, n, m);
    
    cout << "Union of arr1 and arr2 is  " << endl;
    for (auto &val: Union)
        cout << val << " ";
        
    return 0;
}


/*
Input:
- arr1[] = {1, 2, 3, 4, 5}
- arr2[] = {2, 3, 4, 4, 5, 6}
- n = 5, m = 6

Initial Setup:
- i = 0 (points to the first element of arr1)
- j = 0 (points to the first element of arr2)
- Union = {}

Dry Run:

Step 1:
- Compare arr1[i] = 1 with arr2[j] = 2
- Since 1 <= 2, check if Union is empty or last element in Union is not 1.
- Add 1 to Union, increment i.
- Union = {1}, i = 1, j = 0

Step 2:
- Compare arr1[i] = 2 with arr2[j] = 2
- Since 2 <= 2, check if last element in Union is not 2.
- Add 2 to Union, increment i.
- Union = {1, 2}, i = 2, j = 0

Step 3:
- Compare arr1[i] = 3 with arr2[j] = 2
- Since 3 > 2, check if last element in Union is not 2.
- Since 2 is already in Union, increment j.
- Union = {1, 2}, i = 2, j = 1

Step 4:
- Compare arr1[i] = 3 with arr2[j] = 3
- Since 3 <= 3, check if last element in Union is not 3.
- Add 3 to Union, increment i.
- Union = {1, 2, 3}, i = 3, j = 1

Step 5:
- Compare arr1[i] = 4 with arr2[j] = 3
- Since 4 > 3, check if last element in Union is not 3.
- Since 3 is already in Union, increment j.
- Union = {1, 2, 3}, i = 3, j = 2

Step 6:
- Compare arr1[i] = 4 with arr2[j] = 4
- Since 4 <= 4, check if last element in Union is not 4.
- Add 4 to Union, increment i.
- Union = {1, 2, 3, 4}, i = 4, j = 2

Step 7:
- Compare arr1[i] = 5 with arr2[j] = 4
- Since 5 > 4, check if last element in Union is not 4.
- Since 4 is already in Union, increment j.
- Union = {1, 2, 3, 4}, i = 4, j = 3

Step 8:
- Compare arr1[i] = 5 with arr2[j] = 4
- Since 5 > 4, check if last element in Union is not 4.
- Since 4 is already in Union, increment j.
- Union = {1, 2, 3, 4}, i = 4, j = 4

Step 9:
- Compare arr1[i] = 5 with arr2[j] = 5
- Since 5 <= 5, check if last element in Union is not 5.
- Add 5 to Union, increment i.
- Union = {1, 2, 3, 4, 5}, i = 5, j = 4

Step 10:
- i has reached the end of arr1, check remaining elements in arr2.
- Compare arr2[j] = 5 with Union.back() = 5.
- Since 5 is already in Union, increment j.
- Union = {1, 2, 3, 4, 5}, i = 5, j = 5

Step 11:
- Compare arr2[j] = 6 with Union.back() = 5.
- Add 6 to Union.
- Union = {1, 2, 3, 4, 5, 6}, j = 6

Final Union Vector:
- Union = {1, 2, 3, 4, 5, 6}

*/
