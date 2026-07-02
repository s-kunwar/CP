#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        ll current_inv = 0;
        ll total_zeros = 0;
        // Using n+1 to avoid overflow on the very last index [i+1]
        vector<ll> zeroes_suffix(n + 1, 0);

        // Calculate base inversions and build suffix array of zeros
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] == 0) {
                total_zeros++;
                zeroes_suffix[i] = zeroes_suffix[i + 1] + 1;
            } else {
                current_inv += total_zeros;
                zeroes_suffix[i] = zeroes_suffix[i + 1];
            }
        }

        ll max_inv = current_inv;
        ll zeros_to_left = 0;

        for (int i = 0; i < n; i++) {
            ll ones_to_left = i - zeros_to_left;
            ll zeros_to_right = zeroes_suffix[i + 1];

            if (arr[i] == 0) {
                // If we flip 0 to 1:
                // Lose: inversions with 1s to the left
                // Gain: inversions with 0s to the right
                max_inv = max(max_inv, current_inv - ones_to_left + zeros_to_right);
                zeros_to_left++; // Update for the next index
            } else {
                // If we flip 1 to 0:
                // Lose: inversions with 0s to the right
                // Gain: inversions with 1s to the left
                max_inv = max(max_inv, current_inv - zeros_to_right + ones_to_left);
            }
        }

        cout << max_inv << "\n";
    }

    return 0;
}