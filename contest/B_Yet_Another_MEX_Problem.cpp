#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        vector<bool> seen(n + 1, false);
        for (int x : a) {
            if (x <= n) seen[x] = true;
        }

        int mex = 0;
        while (mex <= n && seen[mex]) mex++;

        cout << min(mex, k - 1) << "\n";
    }
    return 0;
}
