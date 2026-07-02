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
        vector<int> a(n), cnt(n + 2, 0);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] <= n) cnt[a[i]]++;
        }

        int mex = 0;
        while (cnt[mex] > 0) mex++;

        if (mex == 0) {
            cout << "NO\n";
        } else if (mex == 1 && cnt[0] > 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
