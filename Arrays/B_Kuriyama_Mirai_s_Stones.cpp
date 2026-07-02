#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<ll> arr(n);
    vector<ll> pf_arr(n + 1, 0);
    vector<ll> pf_sort(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        pf_arr[i + 1] = pf_arr[i] + arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        pf_sort[i + 1] = pf_sort[i] + arr[i];
    }

    int m;
    cin >> m;

    while (m--)
    {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 1)
        {
            cout << pf_arr[r] - pf_arr[l - 1] << "\n";
        }
        else
        {
            cout << pf_sort[r] - pf_sort[l - 1] << "\n";
        }
    }

    return 0;
}