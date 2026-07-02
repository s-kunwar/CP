#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int64 lcm(int64 a, int64 b) {
    return a / __gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int64 n;
        cin >> n;

        int best = 1;

        for (int l = 1; l <= 60; l++) {
            int64 cur_lcm = 1;
            for (int r = l; r <= 60; r++) {
                cur_lcm = lcm(cur_lcm, r);
                if (cur_lcm > n) break;
                if (n % cur_lcm == 0) {
                    best = max(best, r - l + 1);
                }
            }
        }

        cout << best << "\n";
    }

    return 0;
}
