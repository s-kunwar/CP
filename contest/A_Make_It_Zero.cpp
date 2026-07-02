#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int x = 0;
        for (int v : a) x ^= v;

        if (x == 0) {
            // One operation
            cout << 1 << "\n";
            cout << 1 << " " << n << "\n";
        } else if (n % 2 == 0) {
            // Two operations
            cout << 2 << "\n";
            cout << 1 << " " << n << "\n";
            cout << 1 << " " << n << "\n";
        } else {
            // Three operations
            cout << 3 << "\n";
            cout << 1 << " " << n - 1 << "\n";
            cout << 2 << " " << n << "\n";
            cout << 1 << " " << n << "\n";
        }
    }

    return 0;
}
