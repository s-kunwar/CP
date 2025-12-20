#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n, tempdiff = INT_MAX;
        cin >> n;
        vector<int> arr(n);
        
        bool isSorted = true;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(i > 0){
                if(arr[i] < arr[i-1]){
                    isSorted = false;
                }
                tempdiff = min(tempdiff, arr[i] - arr[i-1]);
            }
        }
        
        if(!isSorted) cout << 0 << endl;
        else if(tempdiff == INT_MAX) cout << 0 << endl;
        else cout << (tempdiff / 2) + 1 << endl;
    }
    
    return 0;
}
