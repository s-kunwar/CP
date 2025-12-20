#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){

        int n,odds=0,temp=0;
        cin>>n;
        while(n--){
            cin>>temp;
            if(temp%2!=0) odds++;
        }
        if(odds%2==0) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}