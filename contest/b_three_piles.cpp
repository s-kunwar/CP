#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){

        ll a,b,c;
        cin>>a>>b>>c;

        if(a<b){
            if((a+c-b)>abs(a-b)){cout<<a+c-b<<endl;}
            else{cout<<abs(a-b)<<endl;}
        }
        else{
            cout<<(a+c-b)<<endl;
        }

    }

    return 0;
}