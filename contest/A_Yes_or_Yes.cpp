#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){

        string s;
        cin>>s;
        int cnt=0;

        for(char c:s){
            if(c=='Y') cnt++;
        }
        if(cnt<=1) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}