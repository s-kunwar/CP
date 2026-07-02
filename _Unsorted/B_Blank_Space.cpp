#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;
        vector <int> arr(n);

        for(int i=0; i<n;i++) cin>>arr[i];

        int l=0,r=0,len=0;

        while(l<n){
            while(l<n && arr[l]==1) l++;
            r=l;
            while(r<n && arr[r]==0) r++;
            len=max(len,r-l);
            l=r;
        }

        cout<<len<<endl;


    }

    return 0;
}