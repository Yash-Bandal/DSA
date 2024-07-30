
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
