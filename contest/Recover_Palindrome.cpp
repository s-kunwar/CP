#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){

        int n;
        cin>>n;
        string s;
        cin>>s;
        bool god=true;

        int l=0, r=n-1;
        while(l<=r){
            if(l==r){
                if(s[l]=='?') god=false;
                break;
            }
            if(s[l]==s[r] && s[l]=='?'){
                god=false;
                break;
            }
            l++;
            r--;
        }
        if(god)cout<<"YES\n";
        else cout<<"NO\n";

    }

    return 0;
}