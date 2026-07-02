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

        vector<long long> mex(n), nextMex(n), removeDelta(n);
        unordered_map<int, long long> globalFreq;

        long long totalLen = 0;
        long long baseMexSum = 0;

        for (int i = 0; i < n; i++) {
            int l;
            cin >> l;
            totalLen += l;

            vector<int> arr(l);
            unordered_map<int, int> freq;
            for (int j = 0; j < l; j++) {
                cin >> arr[j];
                freq[arr[j]]++;
                globalFreq[arr[j]]++;
            }

            int m = 0;
            while (freq.count(m)) m++;
            mex[i] = m;

            int m2 = m + 1;
            while (freq.count(m2)) m2++;
            nextMex[i] = m2;

            long long rem = 0;
            for (auto &p : freq) {
                int val = p.first;
                int cnt = p.second;
                if (val < m && cnt == 1) {
                    rem += (val - m);
                }
            }
            removeDelta[i] = rem;

            baseMexSum += m;
        }

        long long totalOps = totalLen * (n - 1);
        long long ans = baseMexSum * totalOps;

        long long removeSum = 0;
        for (int i = 0; i < n; i++) {
            removeSum += removeDelta[i];
        }
        ans += removeSum * (n - 1);

        long long addSum = 0;
        for (int i = 0; i < n; i++) {
            long long occ = globalFreq[mex[i]];
            addSum += (nextMex[i] - mex[i]) * occ;
        }
        ans += addSum;

        cout << ans << "\n";
    }
    return 0;
}
