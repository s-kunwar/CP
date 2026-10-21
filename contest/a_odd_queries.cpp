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

        int n,q;
        cin>>n>>q;

        vector<int>arr(n);
        vector<int>pf(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            if(i==0) {pf[i]=arr[i];}
            else{pf[i]=arr[i]+pf[i-1];}
        }
        while(q--){
            int l,r,k;
            cin>>l>>r>>k;
            l--;
            r--;
            int old_range_sum = pf[r] - (l > 0 ? pf[l-1] : 0);
            int sum = pf[n-1] - old_range_sum + (r - l + 1) * k; 
            if(sum%2==0) cout<<"NO"<<endl;
            else{cout<<"YES"<<endl;}
        }

    }

    return 0;
}