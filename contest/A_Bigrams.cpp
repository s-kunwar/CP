#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int k;
        cin>>k;

        int greater2=0,greater3=0;
        vector<int>cards(k);
        for(int i=0;i<k;i++){
            cin>>cards[i];
            if (cards[i]>=2) greater2++;
            if(cards[i]>2) greater3++;
        }

        if(k==1){
            if(greater3) cout<<"YES\n";
            else cout<<"NO\n";
        } 
        else{
            if(greater2>=2 || greater3) cout<<"YES\n";
        }

    }


    return 0;
}