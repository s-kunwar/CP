#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){


        int n;
        cin>>n;

        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];

        int r=0,parity=(arr[0]%2),prevnum=arr[0],ops=0;

        while(r<n-1){
            r++;
            if(parity==(arr[r]%2)){
                prevnum=arr[r-1]*arr[r];
                //parity=prevnum%2; stays same
                ops++;
            }
            else{
                prevnum=arr[r];
                parity=!parity;
            }
        }

        cout<<ops<<endl;


    }

    return 0;
}