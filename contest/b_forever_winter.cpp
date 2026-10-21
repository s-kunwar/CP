#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> deg(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }

    int x = 0;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] > 1) {
            x++;
        }
    }
    x -= 1; 

    int y = m / x - 1;

    cout << x << " " << y << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
