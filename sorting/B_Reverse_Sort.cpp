#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // 1. Create the target (sorted) version of the string
    string target = s;
    sort(target.begin(), target.end());

    // 2. If already sorted, 0 operations
    if (s == target) {
        cout << 0 << endl;
        return;
    }

    // 3. Find all indices where the original differs from the target
    vector<int> indices;
    for (int i = 0; i < n; i++) {
        if (s[i] != target[i]) {
            indices.push_back(i + 1); // 1-based indexing
        }
    }

    // 4. Output the result (it will always be 1 operation)
    cout << 1 << endl;
    cout << indices.size();
    for (int idx : indices) {
        cout << " " << idx;
    }
    cout << endl;
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