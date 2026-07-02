#include <iostream>
#include <vector>
#include <map>

typedef long long ll;

using namespace std;

int cti(char s){
    return s-'0';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        string num;
        cin>>num;

        vector<ll>val(n+1);
        val[0]=0;
        ll sum=0;
        for(int i=1;i<=n;i++){
            sum+=cti(num[i-1]);
            val[i]=sum-i;
        }

        map<ll,ll>freq;

        for(ll i: val){
            freq[i]++;
        }

        ll total=0;
        for(auto f:freq){
            total+= (f.second)*(f.second-1)/2;
        }

        cout<<total<<endl;



    }

    return 0;
}