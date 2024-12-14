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


//Approach 2
#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

// void div(int n)  //take n=36
vector<int> div(int n)
{
    vector<int> divisors;
    for(int i=1 ; i<=sqrt(n) ; i++){
        if(n % i == 0){
            divisors.push_back(i);
            // cout<<i<<" ";
            if(n/i !=i){
                divisors.push_back(n/i);
                // cout<<n/i<<" ";  //1 36 2 18 3 12 4 9 6  //sort this
            }
        }
}
  return divisors; 
}
int main()
{
    int n;
    cout<<"Enter Number"<<endl;
    cin>>n;
    
    cout<<"The Divisors are :"<<endl;
    vector<int> res;
    res=div(n);
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<< " "; 
    }
    // div(n);
    return 0;
}


//Using Lists

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void div(int n)
{
    list<int> ls;
    for(int i=1 ; i<=sqrt(n) ; i++)
    {
        if(n % i == 0)
        {
           ls.push_back(i);
           if(n/i !=i )
           {
               ls.push_back(n/i);
           }
        }
    }
    // sort(ls.begin(),ls.end());  //list datatype doesnt support random acces iterators..so ls.sort()
    ls.sort();
    
    for(auto i: ls){cout<<i<<" ";}
    
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



//Optimized TC

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void div(int n)
{
    list<int> ls;
    // for(int i=1 ; i<=sqrt(n) ; i++)

    //6*6<=36
    //*7<!=36
    //TC=O(root N)  ....O( √N)  +
        for(int i=1 ; i*i<=n ; i++)
    {
        if(n % i == 0)
        {
           ls.push_back(i);
           if(n/i !=i )
           {
               ls.push_back(n/i);
           }
        }
    }
    // sort(ls.begin(),ls.end());   //not work

    //Internal sort func TC= O(no of factors Log(no of Factors))  ..O(nLog n) +
    ls.sort();
    
    //O(n)...thus total is sum of above all
    for(auto i: ls){cout<<i<<" ";}
    
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

