#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    if (!(cin >> n))
        return;

    vector<int> a(n);
    int min_val = 2e9;
    int max_val = -2e9;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < min_val)
            min_val = a[i];
        if (a[i] > max_val)
            max_val = a[i];
    }

    vector<int> b = a;
    sort(b.begin(), b.end());

    bool already_sorted = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            already_sorted = false;
            break;
        }
    }

    if (already_sorted)
    {
        cout << -1 << "\n";
        return;
    }

    int max_piggy_k = 2e9;

    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            int current_element_limit = max(a[i] - min_val, max_val - a[i]);
            if (current_element_limit < max_piggy_k)
            {
                max_piggy_k = current_element_limit;
            }
        }
    }

    cout << max_piggy_k << "\n";
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