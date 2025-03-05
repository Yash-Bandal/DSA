# C++ Divisors Calculation

## Code Implementations

### Approach 1: Basic Method (Using `void` function)

```cpp
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
```

#### Output Example
```
Enter Number
12
The Divisors are :
1
2
3
4
6
12
```

---

### Approach 2: Using `vector<int>`

```cpp
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
```

#### Output Example
```
Enter Number
15
The Divisors are :
1
3
5
15
```

---

### Approach 3: Optimized Using `sqrt(n)`

```cpp
#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

vector<int> div(int n)
{
    vector<int> divisors;
    for(int i=1 ; i<=sqrt(n) ; i++){
        if(n % i == 0){
            divisors.push_back(i);
            if(n/i !=i){
                divisors.push_back(n/i);
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
    return 0;
}
```

#### Output Example
```
Enter Number
36
The Divisors are :
1 2 3 4 6 9 12 18 36 
```

---

### Approach 4: Using `list<int>`

```cpp
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
```

#### Output Example
```
Enter Number
100
The Divisors are :
1 2 4 5 10 20 25 50 100 
```

---

### Optimized `O(√N log N)` Approach

```cpp
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void div(int n)
{
    list<int> ls;
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
```

#### Output Example
```
Enter Number
49
The Divisors are :
1 7 49 
```

## Conclusion
- **Basic Approach** has `O(N)` complexity.
- **Vector-based Approach** uses `O(N)` space but allows storage of divisors.
- **Optimized Approach** reduces time complexity to `O(√N)`.
- **List-based Approach** uses sorting for efficient output.
- **Final Optimized Approach** uses `O(√N log N)`, making it the most efficient among these methods.




## Previous 
```cpp
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
```

