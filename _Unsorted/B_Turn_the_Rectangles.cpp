#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    int prev=INT_MAX;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(a<=prev && b<=prev){
            if(a>b) prev=a;
            else prev=b;
        }
        else if(a<=prev){
            prev=a;
        }
        else if(b<=prev){
            prev=b;
        }
        else{
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";

    return 0;
}