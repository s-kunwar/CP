#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        int elemnum, sk;
        cin>>elemnum>>sk;

        multiset<int> arr;
        for(int i=0;i<elemnum;i++){
            int val;
            cin>>val;
            arr.insert(val);
        }

        int currk=sk, totalops=0;

        while(!arr.empty()){
            if(*arr.begin()<=currk){
                arr.erase(arr.begin());
                currk++;
                totalops++;
            }else{
                auto it = arr.upper_bound(2*currk+2);
                int splitval = -1;

                if(it != arr.begin()){
                    auto previt = prev(it);
                    if(*previt > currk+1) splitval = *previt;
                }

                if(splitval == -1 && it != arr.end()){
                    splitval = *it;
                }

                if(splitval == -1){
                    splitval = *arr.begin();
                }

                arr.erase(arr.find(splitval));

                int halfval = (splitval+1)/2;
                arr.insert(halfval);
                arr.insert(halfval);

                currk++;
                totalops++;
            }
        }

        cout<<totalops<<"\n";
    }

    return 0;
}