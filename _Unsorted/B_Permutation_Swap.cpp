#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}


int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){cin>>arr[i];}

        int g = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] != i+1) {
                g = gcd(g, abs(arr[i] - (i+1)));
            }
        }
        cout << g << endl;
    }
    

    return 0;
}