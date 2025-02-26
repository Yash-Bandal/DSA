#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        bool flag = true;
        cin >> n;
        int d[n];
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        for (int i = 1; i < n; i++) {
            if (d[i] < d[i - 1]) {
                flag = false;
                break;
            }
        }
        if (flag == true) {
            cout << "Yes" << endl;
        }
        else if (flag == false) {
            cout << "No" << endl;
        }
    }
     return 0;

}
