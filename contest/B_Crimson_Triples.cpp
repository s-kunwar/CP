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
        ll n;
        cin>>n;
        ll ans = 0;
        for (ll b =1; b<= n; ++b) {
            ll count = n/b;
            ans+=count*count;
        }
        cout<<ans<<endl;
        

    }

    return 0;
}