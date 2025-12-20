#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t =1;
    while (t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        vector<int> q(n);

        for(int i=0;i<n;i++) cin>>a[i];
        q[0] = a[0];
        for(int i=0;i<n-1;i++){
            q[i+1] = (int)(q[i])^(int)(a[i+1]);
        }

        int left = 0, right = k-1;

        cout<<1<<" ";

        for (right; right<n ; right++ && left++){
            int cnt = 1;
            for(int j=left; j<right ; j++){
                if (q[j] <= q[right]) cnt++;
            }
            cout<<cnt<<" ";
        }
    }
    return 0;
}