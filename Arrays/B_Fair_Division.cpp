#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int temp,oddcnt=0,evencnt=0;
        for(int i=0;i<n;i++){
            cin>>temp;
            if(temp==2) evencnt++;
            else oddcnt++;
        }
        if((oddcnt==0 && evencnt%2!=0)||(evencnt==0 && oddcnt%2!=0)) cout<<"NO\n";
        else if( oddcnt%2==0 ) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}