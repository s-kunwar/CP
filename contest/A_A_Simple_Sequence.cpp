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
        int n;
        cin>>n;
        for(int i=n;i>=1;i--)cout<<i<<" ";
        cout<<"\n";
    }

    return 0;
}