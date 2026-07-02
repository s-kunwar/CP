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
        string s;
        cin>>n>>s;
        vector<int>p;
        int diff=-1,cnt=0,prev;
        for(int i=0;i<n;i++){
            if (s[i]=='a'){
                cnt++;
                if(cnt==1){
                    p.push_back(i);
                }
                else{
                    for(int prev:p) if(cnt>(i-prev+1)/2) {diff=i-prev+1;break;}
                    if(diff!=-1) break;
                }
            }
        }
        cout<<diff<<endl;
    }

    return 0;
}