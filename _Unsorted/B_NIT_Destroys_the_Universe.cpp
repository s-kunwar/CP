#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){ cin>>arr[i];}

        int segments = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0 && (i == 0 || arr[i-1] == 0))
                segments++;
        }

        cout << min(2, segments) << endl;


    }
    

    return 0;
}