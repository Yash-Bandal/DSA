//Left Rotate
#include <bits/stdc++.h>
using namespace std;

//Brute Force uses xtra array
void rotateArray(int arr[], int n) {
  int temp[n];
  for (int i = 1; i < n; i++) {
    temp[i - 1] = arr[i];
  }
  temp[n - 1] = arr[0];
  for (int i = 0; i < n; i++) {
    cout << temp[i] << " ";
  }
  cout << endl;
}


//Optimal single array
void rotateArray(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Left Rotate :" << endl;
    printArray(arr, n);

    rotateArray(arr, n);

    cout << "After Left Rotate :" << endl;
    printArray(arr, n);

    return 0;
}

//Right rotate by 1 
#include <bits/stdc++.h>
using namespace std;

// Function to find the second largest element in an array
void rotateArray(int arr[], int n)
{
    //either this //comment out any onw while run
    int temp = arr[n - 1];
    for (int i = 1; i < n; i++)
    {
        arr[n - i] = arr[n - i - 1];
    }
    arr[0] = temp;

//or decrement loop
    int temp = arr[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Left Rotate :" << endl;
    printArray(arr, n);

    rotateArray(arr, n);

    cout << "After Left Rotate :" << endl;
    printArray(arr, n);

    return 0;
}



