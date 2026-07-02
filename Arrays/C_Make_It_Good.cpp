#include <iostream>
#include <vector>

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
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int r=n-1;
        bool inc=true;
        while( r>=0 ){
            if(inc==true){
                if(arr[r]>arr[r-1]){inc=false;}
            }
            else{
                if(arr[r]<arr[r-1]){cout<<r<<endl;break;}
            }
            if(r==0) cout<<0<<endl;
            r--;
        }

    }

    return 0;
}