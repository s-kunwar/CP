#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){

        int n,ans;
        cin>>n;

        if(n<=10){
            cout<<n<<endl;
        }
        else if(n<=100){
            cout<<9+(n/10)<<endl;
        }
        else if(n<=1000){
            cout<<9+9+(n/100)<<endl;
        }
        else if(n<=10000){
            cout<<9+9+9+(n/1000)<<endl;
        }
        else if(n<=100000){
            cout<<9+9+9+9+(n/10000)<<endl;
        }
        else{
            cout<<9+9+9+9+9+(n/100000)<<endl;
        }

    }

    return 0;
}