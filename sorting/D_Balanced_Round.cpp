#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){

        int n,k;
        cin>>n>>k;

        vector<int>arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        if(n==1){cout<<0<<endl;continue;}

        sort(arr.begin(),arr.end());

        vector<int>diff(n-1);

        for(int i=1;i<n;i++){
            diff[i-1]=arr[i]-arr[i-1];
        }
        
        int max_len = 0;
        int curr_len = 0;

        for (int x: diff){
            if (x <= k){
                curr_len += 1;
                max_len = max(max_len, curr_len);
            }
            else curr_len = 0 ;
        }

        cout<<n-1-max_len<<endl;

    }

    return 0;
}