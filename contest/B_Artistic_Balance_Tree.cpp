#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<ll> odd, even;
    ll total = 0;

    for (int i = 1; i <= n; i++)
    {
        ll val;
        cin >> val;
        total += val;
        if (i % 2 != 0)
        {
            odd.push_back(val);
        }
        else
        {
            even.push_back(val);
        }
    }

    int o_ops = 0, e_ops = 0;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        if (x % 2 != 0)
            o_ops++;
        else
            e_ops++;
    }

    sort(odd.rbegin(), odd.rend());
    sort(even.rbegin(), even.rend());

    ll marked = 0;

    if (o_ops > 0 && !odd.empty())
    {
        marked += odd[0];
        for (int i = 1; i < (int)odd.size() && i < o_ops; i++)
        {
            if (odd[i] > 0)
            {
                marked += odd[i];
            }
        }
    }

    if (e_ops > 0 && !even.empty())
    {
        marked += even[0];
        for (int i = 1; i < (int)even.size() && i < e_ops; i++)
        {
            if (even[i] > 0)
            {
                marked += even[i];
            }
        }
    }

    cout << total - marked << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}