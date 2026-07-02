#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    long long d;
    cin >> n >> d;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    // Even case: Simple greedy check
    if (n % 2 == 0) {
        for (int i = 0; i < n; i += 2) {
            if (a[i+1] - a[i] > d) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        return;
    }

    // Odd case: Precompute prefix and suffix validity
    // prefix[i] is true if the first i elements (0 to i-1) can be paired
    vector<bool> prefix(n + 1, false);
    prefix[0] = true;
    for (int i = 2; i <= n; i += 2) {
        if (prefix[i - 2] && (a[i - 1] - a[i - 2] <= d)) {
            prefix[i] = true;
        }
    }

    // suffix[i] is true if the elements from i to n-1 can be paired
    vector<bool> suffix(n + 1, false);
    suffix[n] = true;
    for (int i = n - 2; i >= 0; i -= 2) {
        if (suffix[i + 2] && (a[i + 1] - a[i] <= d)) {
            suffix[i] = true;
        }
    }

    // Try removing each element a[i]
    for (int i = 0; i < n; i++) {
        // If we remove index i, we need prefix[i] to be valid 
        // AND the remaining suffix starting at i+1 to be valid
        if (prefix[i] && suffix[i + 1]) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}