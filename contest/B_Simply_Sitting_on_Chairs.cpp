#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> chairs(n);
        for(int i = 0; i < n; i++) {
            cin >> chairs[i];
        }
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(chairs[i] <= i+1) {
                count++;
            }
        }
        cout << count << "\n";
    }

    return 0;
}