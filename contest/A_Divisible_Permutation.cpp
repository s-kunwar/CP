#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        b = a;
        sort(b.begin(), b.end());

        long long ans = 0;
        bool need = false;

        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                need = true;
                ans = max(ans, llabs(a[i] - b[i]));
            }
        }

        if (!need)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }
    return 0;
}
