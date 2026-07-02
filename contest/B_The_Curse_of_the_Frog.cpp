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

        // set p[i] = i xor 1 for i = 2..n-1
        for (int i = 2; i <= n - 1; i++) {
            p[i] = i ^ 1;
        }

        // put 1 at position n
        p[n] = 1;

        // remaining value for position 1
        if (n % 2 == 0) p[1] = n;
        else p[1] = n - 1;

        for (int i = 1; i <= n; i++) {
            cout << p[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
