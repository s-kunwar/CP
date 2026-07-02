#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        vector<int>arr(n);
        for(int i=0;i<n;i++){cin>>arr[i]; if(arr[i]==1) arr[i]+=1;}

        cout<<arr[0];
        for(int y=1;y<n;y++){
            if(arr[y]%arr[y-1]==0) arr[y]+=1;
            cout<<' '<<arr[y];
        }
        cout<<endl;

    }

    return 0;
}