#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map <int,bool> mpp;

bool checkm(int n,int m){
    if(mpp.count(n)) return mpp[n];
    if(n==m) return true;
    if(n<m) return false;

    if(n%3==0 && (checkm(n/3,m)==true || checkm((n/3)*2,m)==true)) return mpp[n]=true;

    return mpp[n]=false;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){

        int n,m;
        cin>>n>>m;

        mpp.clear();

        if(checkm(n,m)) cout<<"YES\n";
        else cout<<"NO\n";

    }


    return 0;
}