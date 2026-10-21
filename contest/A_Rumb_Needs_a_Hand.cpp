#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        
        bool ans = true;
        vector<int> misplaced; 
        vector<int> misind;    

        for (int i = 0; i < n; i++) {
            if (arr[i] != (i + 1)) {
                misplaced.push_back(arr[i]);
                misind.push_back(i + 1);
            }
        }

        int m = misplaced.size();
        for (int i = 0; i < m; i++) {
            if (misplaced[i] != misind[m - 1 - i]) {
                ans = false;
                break;
            }
        }

        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}