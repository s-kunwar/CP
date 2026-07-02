#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;
        int big=-1,sbig=-1;
        vector<int>arr(n);

        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]>=big){sbig=big;big=arr[i]; }
            else if(arr[i]>=sbig) sbig=arr[i];
        }


        if(n==1 && arr[0]>1) cout<<"NO\n";
        else if(big-sbig>1 && n!=1) cout<<"NO\n";
        else cout<<"YES\n";

    }

    return 0;
}