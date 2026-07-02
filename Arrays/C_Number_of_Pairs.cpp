#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long n, l, r; // Use long long to avoid overflow
        cin >> n >> l >> r;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        sort(arr.begin(), arr.end());

        long long total_pairs = 0;
        for (int ind = 0; ind < n; ind++) {
            int ele = arr[ind];

            // 1. Find the first index 'i' such that arr[ind] + arr[i] >= l
            int i = -1;
            int low = ind + 1, high = n - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (ele + arr[mid] >= l) {
                    i = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            // 2. Find the last index 'j' such that arr[ind] + arr[j] <= r
            int j = -1;
            low = ind + 1, high = n - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (ele + arr[mid] <= r) {
                    j = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            // If both bounds were found and i <= j, add the count
            if (i != -1 && j != -1 && i <= j) {
                total_pairs += (j - i + 1);
            }
        }
        cout << total_pairs << "\n";
    }
    return 0;
}