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
        string s;
        cin >> s;

        int ones = 0;
        for (char c : s)
            if (c == '1')
                ones++;

        int added = 0;

        for (int i = 0; i < n;)
        {
            if (s[i] == '1')
            {
                i++;
                continue;
            }

            int j = i;
            while (j < n && s[j] == '0')
                j++;
            int k = j - i;

            bool left = (i > 0 && s[i - 1] == '1');
            bool right = (j < n && s[j] == '1');

            if (left && right)
            {
                added += k / 3;
            }
            else if (left || right)
            {
                added += (k + 1) / 3;
            }
            else
            {
                added += (k + 2) / 3;
            }

            i = j;
        }

        cout << ones + added << '\n';
    }
    return 0;
}
