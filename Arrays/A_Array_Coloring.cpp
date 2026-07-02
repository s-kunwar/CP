#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int,int>> a(n);
        int col=0; //0 red 1 blue
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            col=col^1;
            a[i].second = col; // original index
        }

        sort(a.begin(), a.end());

        int prevcol=a[0].second;
        bool ok=true;
        for (int i = 1; i < n; i++) {
            if(a[i].second==prevcol){ok=false;}
            prevcol=a[i].second;
        }


        cout << (ok ? "YES\n" : "NO\n");
    }
}
