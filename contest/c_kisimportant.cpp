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
        int n,k;
        cin>>n>>k;

        vector<ll>arr(n);
        for(int i=0;i<n;i++){cin>>arr[i];}

        int p=min(k-1,n-k+1);
        ll ans=0;

        for(int i=0;i<p;i++){ans+=max(arr[i],arr[n-1-i]);}
        if((k-1)<=(n-k+1)){
            for(int i=p;i<n-p; i++) ans+=arr[i];
        }
        cout<<ans<<endl;
    }

    return 0;
}