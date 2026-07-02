#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
     while(t--){
        int n,ind;
        cin>>n;

        vector<int>arr(n);

        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(i>0){if(arr[i]!=arr[i-1]) ind=i-1;}
        }

        if(ind==n-2 && arr[ind]==arr[ind-1]) {cout<<(ind+1)+1<<endl;}
        else cout<<ind+1<<endl;

     }

    return 0;
}