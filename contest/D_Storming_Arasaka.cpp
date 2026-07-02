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

        int n; cin>>n;
        int O=0,o=0;
        for(int i=2; i*i<=n; ++i){
            if(n%i==0){
                o++;
                while(n%i==0){
                    O++;
                    n/=i;
                }
            }
        }
        if(n>1){o++;O++;
        }
        cout<<O+o-1<<"\n";
    }

    return 0;
}