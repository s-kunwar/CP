#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q))
        return 0;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<ll> freq(n + 2, 0);

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        freq[l - 1]++;
        freq[r]--;
    }

    for (int i = 1; i < n; i++)
    {
        freq[i] += freq[i - 1];
    }

    freq.resize(n);

    sort(arr.rbegin(), arr.rend());
    sort(freq.rbegin(), freq.rend());

    ll total_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (freq[i] == 0)
            break;
        total_sum += (ll)arr[i] * freq[i];
    }

    cout << total_sum << endl;

    return 0;
}