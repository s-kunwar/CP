#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n,m,k;
        cin >> n >> m >> k;

        vector<long long> a(n), b(m);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<m;i++) cin >> b[i];

        string gdCode;
        cin >> gdCode;

        vector<long long> D(k+1,0);
        for(int i=1;i<=k;i++){
            D[i]=D[i-1]+(gdCode[i-1]=='L'?-1:1);
        }

        int offset=k;
        vector<int> earliest(2*k+1, INT_MAX);
        for(int i=1;i<=k;i++){
            int idx=D[i]+offset;
            if(earliest[idx]==INT_MAX) earliest[idx]=i;
        }

        sort(b.begin(), b.end());

        vector<int> death(n, INT_MAX);
        for(int i=0;i<n;i++){
            long long x=a[i];

            auto it=lower_bound(b.begin(), b.end(), x);
            if(it!=b.end()){
                long long d=(*it)-x;
                if(d<=k){
                    int idx=d+offset;
                    death[i]=min(death[i], earliest[idx]);
                }
            }

            if(it!=b.begin()){
                --it;
                long long d=(*it)-x;
                if(-d<=k){
                    int idx=d+offset;
                    death[i]=min(death[i], earliest[idx]);
                }
            }
        }

        vector<int> cnt(k+2,0);
        for(int i=0;i<n;i++){
            if(death[i]<=k) cnt[death[i]]++;
        }

        int alive=n;
        for(int i=1;i<=k;i++){
            alive-=cnt[i];
            cout<<alive<<' ';
        }
        cout<<"\n";
    }
    return 0;
}
