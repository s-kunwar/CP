#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin>> t;
    while(t--) {
        int n;
        cin>>n;
        vector<long long> a(n);
        for (auto &x:a) cin>>x;

        int answer = 0;

        for (int i = 0; i < n; i++) {
            long long x =-a[i];
            vector<bool>seen(n+2, false);


            for (int j=0;j<n;j++) {
                long long v = a[j]+x;
                if (v >=0 && v<=n)
                    seen[v]= true;
            }
            int mex=0;
            while(seen[mex]) mex++;
            answer=max(answer, mex);
        }

        cout<<answer <<'\n';
    }
    return 0;
}
