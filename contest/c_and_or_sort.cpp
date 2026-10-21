#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int total_zeros = 0;
    for (char c : s)
        if (c == '0')
            total_zeros++;

    if (s[0] == '1')
    {
        cout << total_zeros << "\n";
        return;
    }

    int f1 = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            f1 = i;
            break;
        }
    }

    if (f1 == -1)
    {
        cout << 0 << "\n";
        return;
    }
    vector<int> pref_ones(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pref_ones[i + 1] = pref_ones[i] + (s[i] == '1' ? 1 : 0);
    }

    int ans = n;
    for (int k = f1; k <= n; k++)
    {
        int ones_in_prefix = pref_ones[k];
        int zeros_in_suffix = total_zeros - (k - pref_ones[k]);
        ans = min(ans, ones_in_prefix + zeros_in_suffix);
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
