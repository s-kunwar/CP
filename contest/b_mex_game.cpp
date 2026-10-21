#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n, k;
        cin>>n>>k;

        vector<int>freq(n+2,0);
        for(int i=0,val; i<n;++i) {cin>>val;if (val<=n+1) freq[val]++;}

        for(int i=0; i<=n+1; ++i) {
            if (freq[i] < 2*k) {
                cout << (freq[i] == 2*k-1 ? "YES\n" : "NO\n");
                return;
            }
        }
    }

    return 0;
}