//Brute
#include<bits/stdc++.h>
using namespace std;

  vector<int> RearrangebySign(vector<int>A, int n){
    
  // Define 2 vectors, one for storing positive 
  // and other for negative elements of the array.
  vector<int> pos;
  vector<int> neg;
  
  // Segregate the array into positives and negatives.
  for(int i=0;i<n;i++){
      
      if(A[i]>0) pos.push_back(A[i]);
      else neg.push_back(A[i]);
  }
  
  // Positives on even indices, negatives on odd.
  for(int i=0;i<n/2;i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
  }
  
  
  return A;
    
}

int main() {
    
  // Array Initialisation.
  int n = 4;
  vector<int> A {1,2,-4,-5};

  vector<int> ans = RearrangebySign(A,n);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}



---------------------------------------------------------------------------
  //optimal equal +ve and -ve
  #include<bits/stdc++.h>
using namespace std;

  vector<int> RearrangebySign(vector<int>A){
    
  int n = A.size();
  
  // Define array for storing the ans separately.
  vector<int> ans(n,0);
  
  // positive elements start from 0 and negative from 1.
  int posIndex = 0, negIndex = 1;
  for(int i = 0;i<n;i++){
      
      // Fill negative elements in odd indices and inc by 2.
      if(A[i]<0){
          ans[negIndex] = A[i];
          negIndex+=2;
      }
      
      // Fill positive elements in even indices and inc by 2.
      else{
          ans[posIndex] = A[i];
          posIndex+=2;
      }
  }
  
  return ans;
    
}

int main() {
    
  // Array Initialisation.
  
  vector<int> A = {1,2,-4,-5};

  vector<int> ans = RearrangebySign(A);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}




---------------------------------------------------------------


//..Optimal 1 pass ..unequal +ve and -ve
  #include<bits/stdc++.h>
using namespace std;

  vector<int> RearrangebySign(vector<int>A, int n){
    
  // Define 2 vectors, one for storing positive 
  // and other for negative elements of the array.
  vector<int> pos;
  vector<int> neg;
  
  // Segregate the array into positives and negatives.
  for(int i=0;i<n;i++){
      
      if(A[i]>0) pos.push_back(A[i]);
      else neg.push_back(A[i]);
  }
  
  // If positives are lesser than the negatives.
  if(pos.size() < neg.size()){
      
    // First, fill array alternatively till the point 
    // where positives and negatives ar equal in number.
    for(int i=0;i<pos.size();i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
    }
    
    // Fill the remaining negatives at the end of the array.
    int index = pos.size()*2;
    for(int i = pos.size();i<neg.size();i++){
        
        A[index] = neg[i];
        index++;
    }
  }
  
  // If negatives are lesser than the positives.
  else{
      
      // First, fill array alternatively till the point 
      // where positives and negatives ar equal in number.
      for(int i=0;i<neg.size();i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
  }
    
    // Fill the remaining positives at the end of the array.
    int index = neg.size()*2;
    for(int i = neg.size();i<pos.size();i++){
        
        A[index] = pos[i];
        index++;
    }
  }
  return A;
    
}

int main() {
    
  // Array Initialisation.
  int n = 8;
  vector<int> A {1,-1 ,-2, 3 ,4 ,-5, 6, 8}; 

  vector<int> ans = RearrangebySign(A,n);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}


/*
DRY RUN
Let's walk through a dry run of the given code step by step:

Input:
n = 8
A = {1, -1, -2, 3, 4, -5, 6, 8}
Initial setup:
We initialize two vectors: pos and neg to store the positive and negative values separately.
Loop to segregate positives and negatives:
For i = 0: A[0] = 1 (positive), so pos = {1}
For i = 1: A[1] = -1 (negative), so neg = {-1}
For i = 2: A[2] = -2 (negative), so neg = {-1, -2}
For i = 3: A[3] = 3 (positive), so pos = {1, 3}
For i = 4: A[4] = 4 (positive), so pos = {1, 3, 4}
For i = 5: A[5] = -5 (negative), so neg = {-1, -2, -5}
For i = 6: A[6] = 6 (positive), so pos = {1, 3, 4, 6}
For i = 7: A[7] = 8 (positive), so pos = {1, 3, 4, 6, 8}
Now, pos = {1, 3, 4, 6, 8} and neg = {-1, -2, -5}.

Check condition for the sizes of pos and neg:
pos.size() = 5 and neg.size() = 3. Since pos.size() is greater than neg.size(), we move to the second else block.
Fill the array alternatively:
We need to fill the array alternatively with elements from pos and neg until we run out of negative numbers (neg.size() = 3).

For i = 0: A[0] = pos[0] = 1 and A[1] = neg[0] = -1. So, the array becomes: {1, -1, -2, 3, 4, -5, 6, 8}
For i = 1: A[2] = pos[1] = 3 and A[3] = neg[1] = -2. So, the array becomes: {1, -1, 3, -2, 4, -5, 6, 8}
For i = 2: A[4] = pos[2] = 4 and A[5] = neg[2] = -5. So, the array becomes: {1, -1, 3, -2, 4, -5, 6, 8}
Fill remaining positives:
Since we've exhausted the negative numbers, we now place the remaining positives from pos at the end of the array.

Start at index = 6:
A[6] = pos[3] = 6
A[7] = pos[4] = 8
So the final array becomes: {1, -1, 3, -2, 4, -5, 6, 8}.

Output:
The rearranged array is:
1 -1 3 -2 4 -5 6 8

vector<int> A {1, -1, -2, 3, 4, -5, 6, 8};

*/
