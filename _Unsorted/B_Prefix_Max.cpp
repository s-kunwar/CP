#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        int maxterm=-1;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            maxterm=max(maxterm,temp);
        }
        cout<<maxterm*n<<endl;

    }
    

    return 0;
}