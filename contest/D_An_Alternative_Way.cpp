#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;
        vector<ll> a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n; i++) cin>>b[i];

        ll curP=0, curM=0;
        bool ok=true;
        for(int i=1; i<=n;i++) {
            ll diff=b[i-1]-a[i-1];
            ll xi =(i%2 != 0) ? -diff:diff;

            if (i % 2 == 0) curP=xi+curM;
            else curM =curP -xi;
            if (curP<0 || curM<0) {ok=false;break;}
        }

        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
        
    }



    return 0;
}