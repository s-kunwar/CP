#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;


int cnterr(const string& s,int l,int r) {
    int n=s.length();
    int err=0;
    for (int i=0; i<n; ++i) {
        if (i>=l && i <= r) {
            if (s[i]=='T') err++;
        } 
        else {if (s[i]=='F') err++;}
    }
    return err;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){

        int n; 
        cin>>n;
        string s; 
        cin>>s;

        const int NEG_INF = -1e9;
        vector<vector<int>> dp(n+1, vector<int>(n+1, NEG_INF));
        dp[0][0] = 0;

        auto process = [&](vector<vector<int>>& ndp, int val) {
            int f_inc = (val == 1) ? 1 : 0;
            for (int c = 0; c <= n; c++) {
                for (int b = 0; b <= n; b++) {
                    if (dp[c][b] == NEG_INF) continue;
                    int nc = max(0, c + val);
                    int nb = max(b, nc);
                    ndp[nc][nb] = max(ndp[nc][nb], dp[c][b] + f_inc);
                }
            }
        };

        for (int i = 0; i < n; i++) {
            vector<vector<int>> ndp(n+1, vector<int>(n+1, NEG_INF));
            if (s[i] == 'F') {
                process(ndp, 1);
            } else if (s[i] == 'T') {
                process(ndp, -1);
            } else {
                process(ndp, 1);
                process(ndp, -1);
            }
            dp = ndp;
        }

        int max_min_err = 0;
        for (int c = 0; c <= n; c++) {
            for (int b = 0; b <= n; b++) {
                if (dp[c][b] == NEG_INF) continue;
                max_min_err = max(max_min_err, dp[c][b] - b);
            }
        }

        cout << max_min_err << "\n";
    }

    return 0;
}