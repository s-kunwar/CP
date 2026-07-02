#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<long long> suffixMax(n);
        suffixMax[n-1] = max(a[n-1], b[n-1]);

        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max({a[i], b[i], suffixMax[i + 1]});
        }

        vector<long long> pref(n);
        pref[0] = suffixMax[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + suffixMax[i];
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            long long ans = pref[r - 1] - (l > 1 ? pref[l - 2] : 0);
            cout << ans << " ";
        }
        cout << "\n";
    }
    return 0;
}
