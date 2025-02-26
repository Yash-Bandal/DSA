#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> a(n);
        
        int original_cost = 0, discounted_cost = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            original_cost += a[i];
            discounted_cost += max(0, a[i] - y);
        }

        // Total cost after buying the coupon
        int total_cost_with_coupon = x + discounted_cost;

        // Decide whether to buy the coupon or not
        if (total_cost_with_coupon < original_cost) {
            cout << "COUPON" << endl;
        } else {
            cout << "NO COUPON" << endl;
        }
    }
    return 0;
}
