#include <iostream>
#include <string>
#include <cmath>

// https://codeforces.com/problemset/problem/1881/A

using namespace std;

string getstring(string s, int n)
{
    if (n == 0)
        return s;
    return getstring(s + s, n - 1);
}

bool searchstr(string x, string s)
{
    int len = s.length();
    int r = 0;
    while (r < x.length())
    {
        string ss = x.substr(r, len); // arguments->pos,len
        if (ss == s)
        {
            return true;
        }
        else
            r++;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        string x, s;
        cin >> n >> m;
        cin >> x >> s;

        float mintimes = ceil(log2(m / (float)n));

        if (searchstr(x, s) == true)
            cout << 0; // check if already existing
        else if (mintimes > 0)
        {
            x = getstring(x, mintimes);
            if (searchstr(x, s) == true)
                cout << mintimes;
            else if (searchstr(x + x, s) == true)
                cout << mintimes + 1;
            else
                cout << -1;
        }
        else
        { // for min<=0
            x = x + x;
            (searchstr(x, s) == true) ? cout << 1 : cout << -1;
        }

        cout << "\n";
    }

    return 0;
}