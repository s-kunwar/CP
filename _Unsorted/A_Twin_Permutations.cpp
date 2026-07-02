#include <iostream>
#include <vector>

using namespace std;


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,temp;
        cin>>n;
        int arr[n];
        for(int m=0;m<n;m++) cin>>arr[m];

        for(int x:arr){
            cout<<n-x+1<<" ";
        }
        cout<<endl;


    }

    return 0;
}