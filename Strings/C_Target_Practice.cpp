#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int score = 0;
        for (int i = 0; i < 10; i++) {
            string row;
            cin >> row;
            for (int j = 0; j < 10; j++) {
                if (row[j] == 'X') {
                    int ring = min({i, j, 9 - i, 9 - j});
                    score += ring + 1;
                }
            }
        }
        cout << score << endl;
    }

    return 0;
}
