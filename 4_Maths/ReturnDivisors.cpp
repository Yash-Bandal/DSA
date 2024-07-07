#include<iostream>
using namespace std;

void div(int n)
{
    for(int i=1 ; i<=n ; i++)
    {
        if(n % i == 0)
        {
            cout<<i<<endl;
        }
    }
    
}
int main()
{
    int n;
    cout<<"Enter Number"<<endl;
    cin>>n;
    
    cout<<"The Divisors are :"<<endl;
    div(n);
    return 0;
}

//cant use return type int div(int n use vector funtion instead
#include <iostream>
#include <vector>
using namespace std;

vector<int> div(int n)
{
    vector<int> divisors;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);
        }
    }
    return divisors;
}

int main()
{
    int n;
    cout << "Enter Number" << endl;
    cin >> n;

    cout << "The Divisors are :" << endl;
    vector<int> divisors = div(n);
    for (int i = 0; i < divisors.size(); i++)
    {
        cout << divisors[i] << endl;
    }

    return 0;
}
)
