#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

struct OP{
    int l,r;
    ll d;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k;
    cin>>n>>m>>k;

    vector<ll>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    //input operations
    vector<OP>op(m);
    for(int i=0;i<m;i++){
        cin>>op[i].l;
        cin>>op[i].r;
        op[i].l--;
        op[i].r--;
        cin>>op[i].d;
    }

    vector<ll>opfreq(m+1,0);

    while(k--){
        int l,r;
        cin>>l>>r;
        //0 based indexing l,r ranges from 0 to m-1 now and we have m as the terminating index for all frequency
        l--;
        r--;
        opfreq[l]++;
        opfreq[r+1]--;
    }
    for(int i=1;i<m;i++){opfreq[i]+=opfreq[i-1];}

    vector<ll>diff(n+1,0);

    for(int i=0;i<m;i++){
        ll total_add=opfreq[i]*op[i].d;
        diff[op[i].l]+=total_add;
        diff[op[i].r+1]-=total_add;
    }
    
    for(int i=1;i<n;i++){diff[i]+=diff[i-1];}


    for(int i=0;i<n;i++){
        cout<<arr[i]+diff[i]<<" ";
    }
    cout<<endl;

    return 0;
}