#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n,cnt=1,j=0;
        cin>>n;
        vector <int>arr(n);
        vector<int>ans(2*n);

        for(int i=0;i<n;i++)cin>>arr[i];
        
        ans[j++]=arr[0];
        for(int x=0;x<n-1;x++){
            if(arr[x+1]<arr[x]){
                ans[j++]=arr[x+1];
                cnt++;
            }
            cnt++;
            ans[j++]=arr[x+1];
        }
        cout<<cnt<<endl;
        for(int a=0;a<j;a++) cout<<ans[a]<<' ';
        cout<<endl;
    }


    return 0;
}