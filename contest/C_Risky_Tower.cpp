#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<ll> v(n + 1);
        for (int i = 1; i <= n; i++) cin >> v[i];

        vector<vector<ll>> grid(n + 1, vector<ll>(m));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) cin >> grid[i][j];
        }

        int ans = m;
        vector<ll> top_m;

        for (int i = n; i >= 1; i--) {
            vector<ll> row = grid[i];
            sort(row.begin(), row.end(), greater<ll>());

            vector<ll> next_top;
            merge(top_m.begin(), top_m.end(), row.begin(), row.end(), back_inserter(next_top), greater<ll>());

            if (next_top.size() > (size_t)m) {
                next_top.resize(m);
            }
            top_m = next_top;

            ll sum = 0;
            for (int k = 0; k < (int)top_m.size(); k++) {
                sum += top_m[k];
                if (sum >= v[i]) {
                    ans = min(ans, k + 1);
                    break;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}