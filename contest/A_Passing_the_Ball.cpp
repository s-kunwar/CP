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

        int n;
        string s;
        cin>>n;
        cin>>s;

        int ind=0;
        while(s[ind]!='L'){
            ind++;
        }

        cout<<ind+1<<endl;

    }

    return 0;
}