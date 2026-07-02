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
        vector<int> p(n + 1);

        int i = n;
        while (i > 0) {
            int k = 31 - __builtin_clz(i);
            int start = (1 << k);
            // place range [start..i]
            for (int x = start; x <= i; ++x) {
                p[x] = (start - 1) - (x - start);
            }
            i = start - 1;
        }

        for (int j = 1; j <= n; ++j) {
            cout << p[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
