#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    // Fast I/O is essential for 10^5 operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<ll> a(n + 2, 0); // Padding to avoid boundary checks
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Every subarray contributes at least 1 to the total sum
    ll total_awesomeness = (ll)n * (n + 1) / 2;

    // Initial calculation of transition contributions
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i + 1]) {
            total_awesomeness += (ll)i * (n - i);
        }
    }

    while (m--) {
        int i;
        ll x;
        cin >> i >> x;

        // 1. Remove old contributions of the element at i relative to its neighbors
        if (i > 1 && a[i] != a[i - 1]) {
            total_awesomeness -= (ll)(i - 1) * (n - (i - 1));
        }
        if (i < n && a[i] != a[i + 1]) {
            total_awesomeness -= (ll)i * (n - i);
        }

        // 2. Update the value
        a[i] = x;

        // 3. Add new contributions with the updated value
        if (i > 1 && a[i] != a[i - 1]) {
            total_awesomeness += (ll)(i - 1) * (n - (i - 1));
        }
        if (i < n && a[i] != a[i + 1]) {
            total_awesomeness += (ll)i * (n - i);
        }

        cout << total_awesomeness << "\n";
    }

    return 0;
}