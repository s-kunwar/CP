#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n,temp;
        cin>>n;

        bool overflow=false;
        unordered_map<int,int> freqmap;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>temp;
                freqmap[temp]++;
            }
        }

        for(auto i : freqmap){
            if (i.second>(n*n)-n) overflow=true;
            if (overflow) break;
        }

        overflow ? cout<<"NO\n":cout<<"YES\n";
        
    }

    return 0;
}