#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){

        long long a,b,n;
        cin>>a>>b>>n;

        long long tools[n];
        long long sum=b;
        for(int i=0;i<n;i++){cin>>tools[i];sum+=min(a-1,tools[i]);}

        cout<<sum<<endl;

    }

    return 0;
}