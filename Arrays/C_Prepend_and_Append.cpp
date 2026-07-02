#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){

        int len,n;
        string s;
        cin>>n;
        len=n;
        cin>>s;

        int l=0,r=n-1;

        while(((s[l]=='0' && s[r]=='1')||(s[l]=='1' && s[r]=='0'))&&l<r){
            len-=2;
            l++;
            r--;
        }

        cout<<len<<endl;


    }

    return 0;
}