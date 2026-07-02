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
        cin>>n;
        char buf[105];
        cin>>buf;
        string s(buf);
        
        int runs=1;
        for(int i=1; i<n; i++){
            if(s[i] != s[i-1]) runs++;
        }
        
        cout<<(runs==2?2:1)<<"\n";
    }


    return 0;
}