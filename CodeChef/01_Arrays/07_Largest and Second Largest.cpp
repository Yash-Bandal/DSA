#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
      //  cout<<a[n-1]+a[n-2]<<endl; //cant do ..as we arre asked distinct if 9 9 last it gives 18 we want 9 8 =17
        
        for(int i=n-1;i>0;i--){
            if(a[i] == a[i-1]){
                continue;
            }else{
                cout<<a[i]+a[i-1]<<endl;
                break;
            }
        }
    }
    return 0;
}
//========================= O R ===================================
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
        int firstMax = INT_MIN;
        int secondMax = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (a[i] > firstMax) {
                secondMax = firstMax;
                firstMax = a[i];
            } else if (a[i] > secondMax && a[i] != firstMax) {
                secondMax = a[i];
            }
        }

        int maxSum = firstMax + secondMax;
        cout << maxSum << endl;
    }
}
