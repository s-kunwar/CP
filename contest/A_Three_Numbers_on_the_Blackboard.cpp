#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int a,b,c;
        cin>>a>>b>>c;

        if(a>=b && a>=c && a>(b+c) ) a=b+c;
        else if(b>=a && b>=c && b>(a+c)) b=a+c;
        else if(c>(a+b)) c=a+b;

        cout<<max(a,max(b,c))-min(a,min(b,c))<<endl;

    }

    return 0;
}