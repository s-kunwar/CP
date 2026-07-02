#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){

        int n,h,l;
        cin>>n>>h>>l;

        vector <int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        if (h<l) swap(h, l);
        int A = 0,B=0;

        for(int x:arr) {
            if (x<=l) A++;
            else if (x<=h) B++;
        }

        int ans = min(A, (A+B)/2);
        cout<<ans<<"\n";

    }

    return 0;
}