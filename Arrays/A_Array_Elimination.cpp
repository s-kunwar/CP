#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;
        vector<ll>arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        //to calculate to bit at any positon of a number - (num>>ind)&1
        //if a number is 2pow30, its going to have 30 bits from 0 to 29
        //a1,a2,…,an (0≤ai<2pow30), has bits from 0 to 29 max 

        vector<int>onebitsatind(30);

        for(int i=0;i<n;i++){
            for(int ind=0;ind<30;ind++){
                if( (arr[i]>>ind)&1 ) onebitsatind[ind]++;
            }
        }        

        int G=0;
        for(int c:onebitsatind){G=gcd(c,G);}

        if(G==0){ for(int i=1;i<=n;i++) cout<<i<<' '; }
        else{
            for(int i=1;i<=n;i++){
                if(G%i==0) cout<<i<<' ';
            }
        }
        cout<<endl;

    }

    return 0;
}