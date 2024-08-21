
#include <bits/stdc++.h>
using namespace std;
// when returning a vector create a vector function
vector<int> FindUnion(int arr1[], int arr2[], int n, int m)
{
    vector<int> ans;

    vector<int> visited(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (arr1[i] == arr2[j] && visited[j] == 0)
            {
                ans.push_back(arr1[i]);
                visited[j] = 1;
                break;
            }
            if (arr2[j] > arr1[i])
                break;
        }
    }
    return ans;
}

int main()
{
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    vector<int> Union = FindUnion(arr1, arr2, n, m);
    cout << "Union of arr1 and arr2 is " << endl;
    for (auto &val : Union)
        cout << val << " ";
    return 0;
}
//Union of arr1 and arr2 is 
2 3 4 5 

  
