#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        ll n,k;
        cin>>n>>k;

        ll ans =(1LL<<(n-k+1)) + (2*k) - 2;
        cout<<ans<<endl;
    }

    return 0;
}