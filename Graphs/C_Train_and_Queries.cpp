#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>

using namespace std;


// Custom hash to prevent TLE from collisions
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;


    while(t--){

        int n,k,s;
        cin >>n >> k;
        
        unordered_map<int,pair<int,int>, custom_hash>cords;
        int u;

        for(int i=1;i<=n;i++){
            cin>>u;
            if (cords.find(u) == cords.end()) cords[u] = {i, i};
            else cords[u].second = i;
            
        }

        while(k--) {
            int a, b;
            cin >> a >> b;

            if(cords.count(a) && cords.count(b)) {
                if(cords[a].first <= cords[b].second) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            } else {
                cout << "NO\n";
            }
        }


    }

    return 0;
}