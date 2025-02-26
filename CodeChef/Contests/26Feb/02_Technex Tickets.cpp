//find patterns

//define / solve seperately generally for 1 st element or last as req
#include <iostream>
using namespace std;

void solve() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        if (N == 1) {
            cout << "1"<<endl;
        } else if (N % 2 == 0) {
            cout << (N / 2 + 1) << endl;
        } else {
            cout << (N - 1) / 2 << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
/*
for even N/2 + 1 
for odd (N-1)/2
*/
