#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;
        vector <int> arr(n);
        int zeroes=0;

        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==0 )zeroes++;
        }

        if(arr[0]==1 || arr[n-1]==1){
            cout<<"Alice\n";
        }
        else{
            cout<<"Bob\n";
        }


    }

    return 0;
}