#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(int a, int b, int m) {
    return (a + b + max(a, b) - 1 <= m);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        int L = k - 1;
        int R = n - k;

        int a = 0, b = 0;
        int A = 0, B = 0;

        while (true) {
            // always try to grow the smaller side first
            if (a <= b) {
                if (a < L && check(a + 1, b, m))
                    a++;
                else if (b < R && check(a, b + 1, m))
                    b++;
                else
                    break;
            } else {
                if (b < R && check(a, b + 1, m))
                    b++;
                else if (a < L && check(a + 1, b, m))
                    a++;
                else
                    break;
            }

            A = a;
            B = b;
        }

        cout << A + B + 1 << endl;
    }

    return 0;
}
