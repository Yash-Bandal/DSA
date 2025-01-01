//easy just onclude exclude...TC= O(2*n) *n fpr [rinting each  
//sc=O(n) for n time recursion max not more..here 3 times rec
#include <iostream>
#include <vector>
using namespace std;

void generateSubseq(vector<int> arr, vector<int> res, int i)
{
    if (i >= arr.size())
    {

        // print arrays
        for (int i = 0; i < res.size(); i++)
        {
            cout << "[" << res[i] << "]" << " ";
        }
        cout << endl;
        return;

        // for(auto num :res)
        // {cout<<"["<<num<<"] ";}
        // cout<<endl;
        // return ;

        //  for (int num : res) {
        //     cout << "[" << num << "] ";
        // }
        // cout << endl;
        // return;
    }
    // Include the current element
    res.push_back(arr[i]);
    generateSubseq(arr, res, i + 1);

    // Exclude the current element
    res.pop_back();
    generateSubseq(arr, res, i + 1);
}

int main()
{
    vector<int> arr = {3, 1, 2};
    vector<int> res;

    generateSubseq(arr, res, 0);
    return 0;
}

//aarray pass
//=====================================================================================================

#include <iostream>
#include <vector>
using namespace std;

void generateSubseq(int arr[], vector<int> res, int i)
{

    //we cant do arr.size() this is for vectors  either pass int n in func or size directly
    if (i >= 3)
    {

        // print arrays
        for (int i = 0; i < res.size(); i++)
        {
            cout << "[" << res[i] << "]" << " ";
        }
        cout << endl;
        return;

    }
    // Include the current element
    res.push_back(arr[i]);
    generateSubseq(arr, res, i + 1);

    // Exclude the current element
    res.pop_back();
    generateSubseq(arr, res, i + 1);
}

int main()
{
    int arr[] = {3, 1, 2};
    vector<int> res;

    generateSubseq(arr, res, 0);
    return 0;
}


//
#include <iostream>
#include <vector>
using namespace std;

void generateSubseq(int arr[], int n, vector<int> res, int i)
{
    if (i >= n)
    {
        if (res.empty()) {
            cout << "[]"; // Print empty subset as well
        } else {
            for (int num : res)
            {
                cout << "[" << num << "] ";
            }
        }
        cout << endl;
        return;
    }

    // Include the current element
    res.push_back(arr[i]);
    generateSubseq(arr, n, res, i + 1);

    // Exclude the current element
    res.pop_back();
    generateSubseq(arr, n, res, i + 1);
}

int main()
{
    int arr[] = {3, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array
    vector<int> res;

    generateSubseq(arr, n, res, 0);
    return 0;
}

