#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){

        string s;
        cin>>s;
        int op=0;

        if(s[0]=='u') {
            op++;
            s[0]='s';
        }
        if(s[s.length()-1]=='u'){
            op++;
            s[s.length()-1]='s';
        }

        for(int i=1;i<(s.length()-1);i++){
            if(s[i]=='u' && s[i+1]=='u') {
                op++;
                s[i+1]='s';
            }
        }

        cout<<op<<endl;

    }

    return 0;
}