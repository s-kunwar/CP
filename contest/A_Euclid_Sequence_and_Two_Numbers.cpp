#include <iostream>
#include<algorithm>
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

        vector<int>b(n);
        for(int i=0;i<n;i++){
            cin>>b[i];
        }

        sort(b.rbegin(), b.rend());
        bool flag=true;
        
        if(n==2) {
            cout<<b[0]<<' '<<b[1]<<endl;
            continue;
        }

        for(int i=2;i<n;i++){
            if((b[i-2]%b[i-1]!=b[i])){flag=false;break;}
        }

        if(flag) cout<<b[0]<<' '<<b[1]<<endl;
        else cout<<-1<<endl;

        }
        

    

    return 0;
}