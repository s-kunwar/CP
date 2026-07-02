#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<long long> pf(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += b[i];
            pf[i] = sum;
        }

        sort(a.begin(), a.end());

        long long maxscore = 0;

        for (int i = 0; i < n; ) {
            long long diff = a[i];

            long long swords = n - i;

            int l = 0, r = n - 1, best = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (pf[mid] <= swords) {
                    best = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if (best != -1) {
                maxscore = max(maxscore, diff * (best + 1));
            }
            while (i < n && a[i] == diff) i++;
        }

        cout << maxscore << "\n";
    }

    return 0;
}
