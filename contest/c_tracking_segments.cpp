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

        int n,m;
        cin>>n>>m;
        vector<pair<int,int>>segments;
        for(int i=0;i<m;i++){
            int l,r;
            cin>>l>>r;
            segments.push_back({l,r});
        }

        


    }

    return 0;
}