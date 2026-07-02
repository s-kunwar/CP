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
        ll x;
        cin>>x;

        string s = to_string(x);
        int d = s.size();
        ll y = 1;
        for(int i=0;i<d;i++) y *= 10;
        y += 1;
        cout<<y<<endl;
    }

    return 0;
}