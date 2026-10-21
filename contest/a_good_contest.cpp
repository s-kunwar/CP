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

        int i;
        cin>>i;
        int a,b,c;
        cin>>a>>b>>c;

        cout<<i-min(a,min(b,c))<<endl;

    }

    return 0;
}