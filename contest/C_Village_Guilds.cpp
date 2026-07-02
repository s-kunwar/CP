#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef unsigned long long ull;

struct Node {
    vector<int> children;
    int depth;
};

void get_depths(int u, int d, const vector<vector<int>>& adj, vector<int>& depth) {
    depth[u] = d;
    for (int v : adj[u]) {
        get_depths(v, d + 1, adj, depth);
    }
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }

    vector<int> depth(n + 1);
    get_depths(1, 0, adj, depth);

    vector<vector<int>> nodes_at_depth(n);
    for (int i = 1; i <= n; ++i) {
        nodes_at_depth[depth[i]].push_back(i);
    }

    set<vector<int>> unique_guilds;
    for (int v = 1; v <= n; ++v) {
        vector<vector<int>> current_depth_map(n);
        auto collect = [&](auto self, int u, int d) -> void {
            current_depth_map[d].push_back(u);
            for (int child : adj[u]) {
                self(self, child, d + 1);
            }
        };
        collect(collect, v, 0);

        for (int h = 0; h < n; ++h) {
            if (current_depth_map[h].empty()) break;
            sort(current_depth_map[h].begin(), current_depth_map[h].end());
            unique_guilds.insert(current_depth_map[h]);
        }
    }

    cout << unique_guilds.size() << endl;
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