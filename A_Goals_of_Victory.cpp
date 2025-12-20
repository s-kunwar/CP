#include <iostream>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n,temp,tot=0;
        cin>>n;

        while(--n){
            cin>>temp;
            tot+=temp;
        }

        cout<<(-tot)<<endl;


    }

    return 0;
}