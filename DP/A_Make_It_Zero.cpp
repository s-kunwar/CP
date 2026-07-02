#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        bool allzeroes=true;
        cin>>n;
        vector <int> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            if(arr[i]!=0) allzeroes=false;
        }

        if(n%2==0){

            if(allzeroes){
                cout<<0<<endl;
                continue;
            }
            int xorrval=0;
            for(int num:arr){xorrval=xorrval^num;}
            if(xorrval==0){
                cout<<1<<endl<<1<<' '<<n<<endl;
            }
            else{
                cout<<2<<endl<<1<<' '<<n<<endl<<1<<' '<<n<<endl;
            }

        }
        else{
            if(allzeroes){
                cout<<0<<endl;
                continue;
            }
            int xorrval=0;
            for(int num:arr){xorrval=xorrval^num;}
            if(xorrval==0){
                cout<<1<<endl<<1<<' '<<n<<endl;
                continue;
            }
            cout<<4<<endl<<1<<' '<<n-1<<endl<<1<<' '<<n-1<<endl<<n-1<<' '<<n<<endl<<n-1<<' '<<n<<endl;
        }

    }

    return 0;
}