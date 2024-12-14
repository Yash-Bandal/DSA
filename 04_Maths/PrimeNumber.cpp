#include<iostream>
using namespace std;
// a NUMBER IS PRIME I IT HAS ONLY TWO DIVISORS 
void div(int n)
{
    int count=0;
    // for(int i=1 ; i<=n ; i++)
    // {
    //     if(n % i == 0)
    //     {
    //         count++;
    //         // cout<<i<<endl;
    //     }
    // }   //O(N) TC


    for(int i=1 ; i*i<=n ; i++)
    {
        if(n % i == 0)
        {
            count++;
            if(n/i != i)
            {count++;}
        }
    }
    if(count==2){
        cout<<n<<" is Prime "<<endl;
    }else{
        cout<<n<<" is not Prime "<<endl;
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
