#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin>>t;

    while(t--){

        string s;
        cin>>s;

        int l=0,r=s.size();
        
        for(int i=0;i<(s.size());i++){
            if(s[i]=='1') l=i;
            else if(s[i]=='0' && r==s.size()) r=i+1;
        }

        cout<<r-l<<endl;

    }


    return 0;
}