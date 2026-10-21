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
        int x,y;
        cin>>x>>y;

        if(x==0 && y== 0){cout<<0<<"\n";continue;}

        if(x%2==y%2) {
            if (x>=y)cout<<x<<"\n";
            else cout<<-1<<"\n";
        } 
        else {
            if (x+1>=y)cout<<x+1<<"\n";
            else cout<<-1<<"\n";
        }

    }
    return 0;
}