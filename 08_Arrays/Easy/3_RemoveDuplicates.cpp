//Brute Force

/*
We have to think of a data structure that does not store duplicate elements. So can we use a Hash set? Yes! We can. As we know HashSet only stores unique elements.

Approach: 

Declare a HashSet.
Run a for loop from starting to the end.
Put every element of the array in the set.
Store size of the set in a variable K.
Now put all elements of the set in the array from the starting of the array.
Return K.
*/
#include<bits/stdc++.h>

using namespace std;
int removeDuplicates(int arr[], int n) {
  set < int > set;
  for (int i = 0; i < n; i++) {
    set.insert(arr[i]);
  }
  int k = set.size();
  int j = 0;
  for (int x: set) {
    arr[j++] = x;
  }
  return k;
}
int main() {
  int arr[] = {1,1,2,2,2,3,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = removeDuplicates(arr, n);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
}


//Optimized 2 pointers


#include<bits/stdc++.h>

using namespace std;
int removeDuplicates(int arr[], int n)
{
  int i = 0;
  for (int j = 1; j < n; j++) {
    if (arr[i] != arr[j]) {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;
}
int main() {
  int arr[] = {1,1,2,2,2,3,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = removeDuplicates(arr, n);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
}

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int removeDuplicates(int *arr, int n) {
  set<int> set;

  for (int i = 0; i < n; i++) {
    set.insert(arr[i]);
  }
  int setSz = set.size();
  int j = 0;
  for (int x : set) {
    arr[j++] = x;
  }
  return setSz;
}

// Two pointer method
int removeDuplicates2(int *arr, int n) {
  if (n == 0) return 0;  // edge case for empty array
  int i = 0;
  for (int j = 1; j < n; j++) {
    if (arr[j] != arr[i]) {
      arr[++i] = arr[j];
    }
  }
  return i + 1;
}

int main() {
  int arr[] = {1, 1, 2, 2, 2, 3, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  int arr2[] = {1, 1, 2, 2, 2, 3, 3, 4, 4, 4};
  int N = sizeof(arr2) / sizeof(arr2[0]);

  int k = removeDuplicates(arr, n);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  int m = removeDuplicates2(arr2, N); // use N instead of n here
  cout << "The array after removing duplicate elements using the two-pointer technique is " << endl;
  for (int i = 0; i < m; i++) {
    cout << arr2[i] << " ";
  }
}
