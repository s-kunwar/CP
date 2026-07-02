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
        bool diff=false;

        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[0]!=arr[i]) diff=true;
        }

        if(diff){
            cout<<"YES\n";
            sort(arr.begin(),arr.end(),greater<int>());       
            int l=0,r=n-1;
            while(l<=r){
                if(l==r){cout<<arr[l]<<' ';l++;}
                else{
                    cout<<arr[l]<<' ';
                    cout<<arr[r]<<' ';
                    l++;
                    r--;
                }
            }
            cout<<endl;
        }
        else{
            cout<<"NO\n";
        }



    }

    return 0;
}