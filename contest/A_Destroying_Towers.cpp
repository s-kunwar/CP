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

        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        int sum=a[0];
        int smallest=a[0];

        for(int i=1;i<n;i++){
            if(a[i]<smallest){
                smallest=a[i];
            }
            sum+=smallest;
        }

        cout<<sum<<endl;

    }

    return 0;
}