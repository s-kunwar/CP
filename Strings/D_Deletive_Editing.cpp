#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        string s, t;
        cin >> s >> t;

        vector<int> sa(26, 0), ta(26, 0);
        for (char c : s) sa[c - 'A']++;
        for (char c : t) ta[c - 'A']++;

        bool ok = true;
        vector<int> need(26, 0);

        for (int i = 0; i < 26; i++) {
            if (sa[i] < ta[i]) {
                ok = false;
                break;
            }
            need[i] = sa[i] - ta[i];
        }

        if (!ok) {
            cout << "NO\n";
            continue;
        }

        string rem;
        for (char c : s) {
            int idx = c - 'A';
            if (need[idx] > 0) {
                need[idx]--; // delete this occurrence
            } else {
                rem.push_back(c);
            }
        }

        cout << (rem == t ? "YES\n" : "NO\n");
    }

    return 0;
}
