#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/**
 * To efficiently identify all unique guilds, we observe that a guild
 * is a set of nodes at distance h from v within the subtree of v.
 * Since we need to identify sets, we can represent each guild by 
 * a sorted vector of node indices.
 */

void get_guilds(int u, const vector<vector<int>>& adj, vector<vector<int>>& all_guilds) {
    // For every node u, it is the root of its own subtree.
    // We collect all nodes at distance h from u within its subtree.
    
    // Using a vector of vectors to store nodes at each level h for current root u
    vector<vector<int>> levels;
    
    auto dfs = [&](auto self, int curr, int dist) -> void {
        if (levels.size() <= dist) levels.resize(dist + 1);
        levels[dist].push_back(curr);
        for (int v : adj[curr]) {
            self(self, v, dist + 1);
        }
    };
    
    dfs(dfs, u, 0);
    
    for (auto& guild : levels) {
        sort(guild.begin(), guild.end());
        all_guilds.push_back(guild);
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

    vector<vector<int>> all_guilds;
    for (int i = 1; i <= n; ++i) {
        get_guilds(i, adj, all_guilds);
    }

    sort(all_guilds.begin(), all_guilds.end());
    int unique_count = 0;
    if (!all_guilds.empty()) {
        unique_count = 1;
        for (size_t i = 1; i < all_guilds.size(); ++i) {
            if (all_guilds[i] != all_guilds[i - 1]) {
                unique_count++;
            }
        }
    }

    cout << unique_count << endl;
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