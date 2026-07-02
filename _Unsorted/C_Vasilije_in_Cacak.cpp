#include <iostream>
#include <vector>

using namespace std;

long long sum(long long s,long long e){
    s--;
    long long sum=(e*(e+1)/2)-(s*(s+1)/2);
    return sum;
}

int main(){

    int t;
    cin>>t;

    while(t--){

        long long n,k,x;
        cin>>n>>k>>x;

        long long maxsum=sum(n-k+1,n),minsum=sum(1,k);

        if(x<=maxsum && x>=minsum) cout<<"YES\n";
        else cout<<"NO\n";


    }

    return 0;
}