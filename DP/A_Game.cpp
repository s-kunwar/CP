#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin>>t;

    while(t--){

        int k;
        cin>>k;
        int t1=0,t2=0;
        int a,b;
        int x,y;

        cin>>a>>b;
        cin>>x>>y;

        t1=a+x;
        t2=b+y;

        if(t2+k > t1) cout<<"YES\n";
        else if((t2+k)==t1){
            if(a>b && x>y) cout<<"NO\n";
            else cout<<"YES\n";
        }
        else cout<<"NO\n";

    }

    return 0;
}