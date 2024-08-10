//O(2N) TC
 #include <bits/stdc++.h>
 
using namespace std;
int findSecondLargestElement(int arr[], int n) {
 
  int largest = arr[0];
  int secLargest=INT_MIN;
  for (int i = 0; i < n; i++) {
    if (largest < arr[i]) {
      largest = arr[i];
    }
  }
  //first find largest
    for (int i = 0; i < n; i++) {
    if (arr[i]>secLargest && arr[i] != largest) {
      secLargest = arr[i];
    }
  }
  //we now again repeat the above but just check if elem is not equal to largest..thus returning sec large


  return secLargest;
}
int main() {
  int arr1[] = {2,5,1,3,0};
  int n = 5;
  int secLarg = findSecondLargestElement(arr1, n);
  cout << "The Second largest element in the array is: " << secLarg << endl;
 
  int arr2[] =  {8,10,5,7,9};
  n = 5;
  secLarg = findSecondLargestElement(arr2, n);
  cout << "The second largest element in the  2nd array is: " << secLarg<<endl;
  return 0;
}



//optimized 1 loop
#include <bits/stdc++.h>
using namespace std;

// Function to find the second largest element in an array
int findSecondLargestElement(int arr[], int n) {
    int largest = arr[0];         // Initialize largest as the first element
    int secLargest = INT_MIN;     // Initialize second largest as a very small value

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {   // If current element is greater than the largest
            secLargest = largest; // Update second largest to be the previous largest
            largest = arr[i];     // Update largest to the current element
        }
        else if (arr[i] < largest && arr[i] > secLargest) {
            secLargest = arr[i];  // Update second largest if current element is between largest and secLargest
        }
    }

    return secLargest; // Return the second largest element
}

int main() {
    int arr1[] = {2, 5, 1, 3, 0};
    int n = 5;
    int secLarg = findSecondLargestElement(arr1, n);
    cout << "The second largest element in the array is: " << secLarg << endl;

    int arr2[] = {8, 10, 5, 7, 9};
    n = 5;
    secLarg = findSecondLargestElement(arr2, n);
    cout << "The second largest element in the 2nd array is: " << secLarg << endl;

    return 0;
}

//Optimized both
#include <bits/stdc++.h>
using namespace std;

// Function to find the second largest element in an array
int findSecondLargestElement(int arr[], int n)
{
    int largest = arr[0];     // Initialize largest as the first element
    int secLargest = INT_MIN; // Initialize second largest as a very small value

    // SecLarg

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {                         // If current element is greater than the largest
            secLargest = largest; // Update second largest to be the previous largest
            largest = arr[i];     // Update largest to the current element
        }
        else if (arr[i] < largest && arr[i] > secLargest)
        {
            secLargest = arr[i]; // Update second largest if current element is between largest and secLargest
        }
    }
    return secLargest;
}

int findSecSmallest(int arr[], int n)
{
    int smallest = arr[0];
    int secSmallest = INT_MAX;
    // SecSmall

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            secSmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] > smallest && arr[i] < secSmallest)
        {
            secSmallest = arr[i];
        }
    }
    return secSmallest;
}

int main()
{
    int arr1[] = {2, 5, 1, 3, 0};
    int n = 5;
    int secLarg = findSecondLargestElement(arr1, n);
    cout << "The second largest element in the 1st array is: " << secLarg << endl;

    int arr2[] = {8, 10, 5, 7, 9};
    n = 5;
    secLarg = findSecondLargestElement(arr2, n);
    cout << "The second largest element in the 2nd array is: " << secLarg << endl;

    int secSmallest = findSecSmallest(arr1, n);
    cout << "The second Smallest element in the 1st array is: " << secSmallest << endl;

    secSmallest = findSecSmallest(arr2, n);
    cout << "The second smallest element in the 2nd array is: " << secSmallest << endl;

    return 0;
}


