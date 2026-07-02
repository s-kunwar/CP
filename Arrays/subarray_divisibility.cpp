#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<ll> arr(n);
    // Using a map or array to store frequencies of remainders
    // Since remainders are 0 to n-1, a vector is faster than unordered_map
    vector<ll> freq(n, 0);
    
    // The "empty" prefix sum is always 0.
    freq[0] = 1; 

    ll current_sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        current_sum += arr[i];

        // Normalize the remainder to be in range [0, n-1]
        ll rem = current_sum % n;
        if (rem < 0) rem += n; 

        freq[rem]++;
    }

    ll total = 0;
    for(int i = 0; i < n; i++) {
        // Combination formula: nCr where r=2 -> n*(n-1)/2
        if (freq[i] > 1) {
            total += (freq[i] * (freq[i] - 1)) / 2;
        }
    }

    cout << total << endl;

    return 0;
}