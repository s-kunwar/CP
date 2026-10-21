#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <functional>
#include <cmath>

using namespace std;

typedef long long ll;

const int NEG = -1000000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int c0 = 0, c1 = 0;
        for (char c : s) {
            if (c == '0') c0++;
            else c1++;
        }

        map<tuple<int, int, int>, int> dp;

        function<int(int, int, int)> solve = [&](int i, int last, int diff) {
            tuple<int, int, int> key = {i, last, diff};
            if (dp.count(key)) return dp[key];

            if (i == n) {
                if (abs((c0 - c1) - diff) <= 1) return 0;
                return NEG;
            }

            int ans = solve(i + 1, last, diff);

            int cur = s[i] - '0';
            if (last == 2 || last != cur) {
                int ndiff = diff + (cur == 0 ? 1 : -1);
                ans = max(ans, 1 + solve(i + 1, cur, ndiff));
            }

            return dp[key] = ans;
        };

        int keep = solve(0, 2, 0);

        if (keep < 0) cout << -1 << "\n";
        else cout << n - keep << "\n";
    }

    return 0;
}