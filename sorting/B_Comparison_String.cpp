#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        string s;
        cin>>s;

        char prev=s[0];
        int i=0,curr=0,maxlen=0;

        while(i<n){
            if(s[i]==prev){curr++;}
            else{maxlen=max(maxlen,curr);curr=1;prev=s[i];}
            i++;
        }
        maxlen=max(maxlen,curr);
        cout<<maxlen+1<<endl;

    }
    

    return 0;
}