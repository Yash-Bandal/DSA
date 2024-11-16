// Covers all basisc of language first ..loops statements .etc
 
//pass By reference 
#include <iostream> 
using namespace std;
void addAndPrintSum(int &num1, int &num2)         
{
    // cout<<num1<<num2<<endl;  //here copy of a and b 70 70 brought up
    num1=50;    //we made changes in copy
    num2=50;
    cout << "Sum: " << num1 + num2 << endl;
}
 
int main()                                    //cin 
{
    int a=70; //actual..copy sent above
    int b=70;
    addAndPrintSum(a, b);   //output is 100..50+50 not 70+70 as local preference..
                            //conclusion is that a and b remain 70 even after call
    cout<<"a="<<a<<" "<<"b="<<b<<endl;    //a=70 and b=70 not a=50 b=50
    
    return 0;
}

//pass By Value
#include <iostream>
using namespace std;


void addAndPrintSum(int num1, int num2)         
{
    // cout<<num1<<num2<<endl;  //here copy of a and b 70 70 brought up
    num1=50;    //we made changes in copy
    num2=50;
    cout << "Sum: " << num1 + num2 << endl;
}

int main()                                    //cin 
{
    int a=70; //actual..copy sent above
    int b=70;
    addAndPrintSum(a, b);   //output is 100..50+50 not 70+70 as local preference..
                            //conclusion is that a and b remain 70 even after call
    cout<<"a="<<a<<" "<<"b="<<b<<endl;    //a=70 and b=70 not a=50 b=50
    
    return 0;
}
