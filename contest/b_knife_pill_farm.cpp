#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){

        int n,m;
        cin>>n>>m;

        vector<ll>arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        if(m==1){
            ll ans=arr[0];
            for(int i=1;i<n;i++) ans=max(ans,arr[i]);
            cout<<ans<<"\n";
            continue;
        }

        priority_queue<ll>pq;
        ll sum=0;
        
        for(int i=0;i<m-1;i++){
            pq.push(arr[i]);
            sum+=arr[i];
        }

        ll ans=(m*arr[m-1])-sum;

        for(int i=m;i<n;i++){
            if(arr[i-1]<pq.top()){
                sum-=pq.top();
                sum+=arr[i-1];
                pq.pop();
                pq.push(arr[i-1]);
            }
            ans=max(ans,(m*arr[i])-sum);
        }

        cout<<ans<<"\n";
    }

    return 0;
}