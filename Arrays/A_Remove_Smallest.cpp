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

        vector<int>arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        sort(arr.begin(),arr.end());

        int rem=0;
        for(int i =1;i<n;i++){
            if(abs(arr[i]-arr[i-1])>1){
                rem++;
                break;
            }            
        }

        if(rem) cout<<"NO\n";
        else cout<<"YES\n";

    }

    return 0;
}