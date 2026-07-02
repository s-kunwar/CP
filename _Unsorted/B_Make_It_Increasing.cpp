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
        for(int i=0;i<n;i++){cin>>arr[i];}

        int cnt=0;
        for(int i=n-2;i>=0;i--){
            while(arr[i]>=arr[i+1] && arr[i]>0){
                arr[i]=arr[i]/2;
                cnt++;
            }
            if(arr[i]==arr[i+1]){
                cnt=-1;
                break;
            }
        }

        cout<<cnt<<endl;

    }

    return 0;
}