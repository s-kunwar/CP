#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){

        int n,oddcnt=0,evencnt=0;
        cin>>n;

        int temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            if(i%2==0 && temp%2!=0) oddcnt++;
            if(i%2!=0 &&temp%2==0) evencnt++;
        }

        if(oddcnt==evencnt) cout<<oddcnt<<endl;
        else cout<<-1<<endl;
    }

    return 0;
}