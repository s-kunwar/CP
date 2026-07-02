#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){

        int n,k;
        cin>>n>>k;

        int p=k/(n-1);
        int rem=k-((n-1)*p);

        int term=n*p;

        if(rem!=0) cout<<term+rem<<endl;
        else  cout<<term+rem-1<<endl;
    }

    return 0;
}