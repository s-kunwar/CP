#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){

        int x,k;
        cin>>x>>k;

        if(x%k==0){
            cout<<2<<endl<<x-k-1<<' '<<k+1<<endl;
        }
        else{
            cout<<1<<'\n'<<x<<endl;
        }


    }

    return 0;
}