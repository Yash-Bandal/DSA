#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        // your code goes here
        if(n == 1){
            cout<<0<<endl;
            continue;
        }
        int cnt = 0;
        int minEle = INT_MAX;
        for(int i=0;i<n;i++){
            minEle = min(minEle,a[i]);
        }
        for(int i=0;i<n;i++){
            if(a[i] ==minEle){
                cnt++;
            }
        }
        cout<<n-cnt<<endl;
        
    }

}
