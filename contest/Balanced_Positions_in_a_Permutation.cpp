#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    for (int i = 0; i < n; i++)
    {
        int li = 0;
        int ri = 0;

        for (int j = 0; j < i; j++)
        {
            if (p[j] < p[i])
                li++;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (p[j] > p[i])
                ri++;
        }

        if (li == ri)
        {
            count++;
        }
    }

    cout << count << "\n";
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