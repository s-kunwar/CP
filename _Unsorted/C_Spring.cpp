#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;


long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return std::abs(a); // Return absolute value
}
long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0; // LCM of any number with 0 is 0
    long long res = std::abs(a / gcd(a, b) * b); // Use formula: LCM = (a*b)/GCD
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){

        ll a,b,c;
        ll m;
        cin>>a>>b>>c>>m;

        ll y=lcm(a,b);
        ll z=lcm(b,c);
        ll x =lcm(y,c);
        ll w=lcm(a,c);

        ll s1,s2,s3;

        s2=6*(m/b)-3*(m/y)-3*(m/z)+2*(m/x);
        s1=6*(m/a)-3*(m/w)-3*(m/y)+2*(m/x);
        s3=6*(m/c)-3*(m/w)-3*(m/z)+2*(m/x);

        cout<<s1<<" "<<s2<<" "<<s3<<endl;

    }

    return 0;
}