#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    if (!(cin >> n))
        return;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    long long total_cost = 0;
    bool can_absorb = false;

    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > 1)
        {
            total_cost += a[i];
            can_absorb = true;
        }
        else
        {
            if (!can_absorb)
            {
                total_cost += 1;
                can_absorb = true;
            }
        }
    }

    cout << total_cost % 676767677 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        solve();
    }
    return 0;
}