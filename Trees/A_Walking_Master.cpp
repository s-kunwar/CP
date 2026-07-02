#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){

        int a,b,x,y;
        cin>>a>>b>>x>>y;

        if(y<b) cout<<-1<<endl;
        else if(x>(a+y-b)) cout<<-1<<endl;
        else cout<<(2*y-2*b+a-x)<<endl;

    }

    return 0;
}