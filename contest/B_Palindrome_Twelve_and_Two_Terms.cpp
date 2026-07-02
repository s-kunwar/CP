#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        if(n==10){cout<<-1<<"\n";continue;}
        ll a;

        if(n>=22){
            int rem=n%12;
            if(rem<=9) a=rem;
            else if(rem==10) a=22;
            else a=11;
        }
        else{
            if(n<=9) a=n;
            else if(n==11) a=11;
            else a=n%12;
        }

        cout<<a<<" "<<n-a<<"\n";
    }
    return 0;


}