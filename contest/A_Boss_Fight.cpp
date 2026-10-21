#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    map<ll, int> freq;
    ll total_sum = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total_sum += a[i];
        freq[a[i]]++;
    }
    
    ll x = 0;
    int f_max = 0;
    for (auto const& p : freq) {
        if (p.second > f_max) {
            f_max = p.second;
            x = p.first;
        }
    }
    
    int C = n - f_max;
    if (f_max <= C + 2) {
        cout << total_sum << "\n";
    } else {
        ll sum_other = total_sum - (ll)f_max * x;
        ll ans = sum_other + (ll)(C + 2) * x;
        cout << ans << "\n";
    }
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