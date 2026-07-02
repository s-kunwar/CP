#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> freq(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            freq[x]++;
        }

        vector<vector<int>> divisors(n + 1);
        for (int d = 1; d <= n; d++) {
            if (freq[d] == 0) continue;
            for (int m = d; m <= n; m += d) {
                divisors[m].push_back(d);
            }
        }

        vector<int> dp(n + 1, INF);

        for (int d = 1; d <= n; d++) {
            if (freq[d] > 0) dp[d] = 1;
        }

        for (int x = 2; x <= n; x++) {
            for (int d : divisors[x]) {
                if (dp[x / d] != INF) {
                    dp[x] = min(dp[x], dp[x / d] + 1);
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (dp[i] == INF) cout << -1;
            else cout << dp[i];
            if (i < n) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
