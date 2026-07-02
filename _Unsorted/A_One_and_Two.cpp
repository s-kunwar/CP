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

        int twos=0;
        for(int i=0;i<n;i++){
            if(arr[i]==2) twos++;
        }

        int lefttwos=0,righttwos=twos;
        int k=-1;
        for(int i=0;i<=n-2;i++){
            if(arr[i]==2){lefttwos++;righttwos--;}
            if(lefttwos==righttwos){k=i+1;break;}
        }

        cout<<k<<endl;


    }

    return 0;
}