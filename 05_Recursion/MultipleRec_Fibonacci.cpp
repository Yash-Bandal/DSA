//Basic Fibo

#include<bits/stdc++.h>
using namespace std; 

int main() {
  int size = 7;  //last index size-1..print till 
  int n=size-1;
  if (n == 0) {
    cout << 0;
  } else if (n == 1) {
    cout << 0 << " " << 1 << "\n";
  } else {
    int fib[size];  //array declare
    fib[0] = 0;  //first term
    fib[1] = 1;   //sec term
    for (int i = 2; i <= n; i++) {
      fib[i] = fib[i - 1] + fib[i - 2];
    }
    cout<<"The Fibonacci Series up to "<<n<<"th term:"<<endl;
    for (int i = 0; i <= n; i++) {
      cout << fib[i] << " ";
    }
  }
}
//Time Complexity: O(n)+O(n), for calculating and printing the Fibonacci series.
//Space Complexity: O(n), for storing Fibonacci series.




#include<bits/stdc++.h>
using namespace std;
int main() {
	int n = 5;
	if (n == 0) {
	    cout<<"The Fibonacci Series up to "<<n<<"th term:"<<endl;
		cout << 0;
	}
	else {
		int secondLast = 0;//for (i-2)th term
		int last = 1;//for (i-1)th term
		cout<<"The Fibonacci Series up to "<<n<<"th term:"<<endl;
		cout << secondLast << " " << last << " ";
		int cur; //for ith term
		for (int i = 2; i <= n; i++) {
			cur = last + secondLast;
			secondLast = last;
			last = cur;
			cout << cur << " ";
		}
	}
}

// 
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n = 5;
	if (n == 0) {
	    cout<<"The Fibonacci Series up to "<<n<<"th term:"<<endl;
		cout << 0;
	}
	else {
		int firstTerm = 0;//for (i-2)th term
		int secTerm = 1;//for (i-1)th term
		cout<<"The Fibonacci Series up to "<<n<<"th term:"<<endl;
		cout << firstTerm << " " << secTerm << " ";
		int thirdTerm; //for ith term
		for (int i = 2; i <= n; i++) {
			thirdTerm = secTerm + firstTerm;
			firstTerm = secTerm;
			secTerm = thirdTerm;  //move forward by 1
			cout <<thirdTerm << " ";
		}
	}
}

//Recursion
#include<bits/stdc++.h>
using namespace std;

int fibonacci(int N){
   
   // Base Condition.
   if(N <= 1)
   {
       return N;
   }

   // Problem broken down into 2 functional calls
   // and their results combined and returned.
   int last = fibonacci(N-1);
   int slast = fibonacci(N-2);
   
   return last + slast;

}

int main(){
  
  // Here, let’s take the value of N to be 4.
  int N = 4;
  cout<<fibonacci(N)<<endl;
  return 0;

}

//TC not exact but near 2^N each func calls 2 func...the further call more 2 ..thus call all sum using GP 2 +4+16+...+2^n
