#include <bits/stdc++.h>
using namespace std;
int main()

{

    int n;
    cout << "Enter size of array" << endl;
    cin >> n;
    int arr[n];
    cout<<"Enter array with max element 12"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //create hash array basic that holds all elements of above arary as index
    int hash[13]={0};  //as we have max element 12 in array

     for (int i = 0; i < n; i++)
    {
        hash[arr[i]]+=1;  //hash array index is the value here of the array created above
        //hash[key]=value..here key is the num whise count you want
    }
cout<<"Enter no of queries"<<endl;
int q;  //mu,ber of queries
cin>>q;

while (q--)
{
    int num;
    cout<<"Enter num whose count you want"<<endl;
    cin>>num;
    cout<<hash[num]<<endl;
}

    return 0;
}
