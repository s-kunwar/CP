#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long a, b;
        cin >> a >> b;

        long long kx, ky, qx, qy;
        cin >> kx >> ky;
        cin >> qx >> qy;

        // All 8 knight moves
        vector<pair<long long, long long>> moves = {
            { a,  b}, { a, -b}, {-a,  b}, {-a, -b},
            { b,  a}, { b, -a}, {-b,  a}, {-b, -a}
        };

        set<pair<long long, long long>> kingPos;
        set<pair<long long, long long>> queenPos;

        // Positions attacking the king
        for (int i = 0; i < 8; i++) {
            long long dx = moves[i].first;
            long long dy = moves[i].second;
            kingPos.insert({kx + dx, ky + dy});
        }

        // Positions attacking the queen
        for (int i = 0; i < 8; i++) {
            long long dx = moves[i].first;
            long long dy = moves[i].second;
            queenPos.insert({qx + dx, qy + dy});
        }

        // Count common positions
        int count = 0;
        for (auto p : kingPos) {
            if (queenPos.count(p)) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
