#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){

        int n,m,h;
        cin>>n>>m>>h;

        vector<long long> orig(n);
        for (int i = 0; i < n; i++) {cin >> orig[i];}
        vector<long long> delta(n, 0);
        vector<int> gen(n, -1);

        int curGen = 0;
        while (m--) {
            int b;
            long long c;
            cin >> b >> c;
            b--;

            if (gen[b] != curGen) {delta[b] = 0;gen[b] = curGen; }

            delta[b] += c;
            if (orig[b] + delta[b] > h) curGen++;
        }

        for(int i = 0; i < n; i++){
            if (gen[i] == curGen) {cout<<orig[i]+delta[i]<<" "; } 
            else {cout << orig[i] << " "; }
        }
        cout<<"\n";
    }
    return 0;
}
