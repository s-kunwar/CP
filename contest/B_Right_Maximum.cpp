#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){

        int n,temp;
        cin>>n;

        vector<int>arr(n);
        vector<int>ind(n);
        for(int i=0;i<n;i++) {cin>>arr[i];ind[i]=i;}

        /*
        //custom sort for indexes
        for(int i=0;i<n;i++){
            for(int j=0;j<(n-i-1);j++){
                if(arr[ind[j]]<arr[ind[j+1]] || (arr[ind[j]] == arr[ind[j+1]] && ind[j] < ind[j+1]) ){
                    temp=ind[j];
                    ind[j]=ind[j+1];
                    ind[j+1]=temp;
                }
            }
        }
        */
        // Optimized sorting: O(n log n)
        sort(ind.begin(), ind.end(), [&](int i, int j) {
            if (arr[i] != arr[j]) {
                return arr[i] > arr[j]; // Primary: Higher value first
            }
            return i > j; // Secondary: Rightmost index first (for ties)
        });

        int sum = 0;
        int last_pos = n;

        for (int i : ind) {
            if (i < last_pos) {
                sum++;
                last_pos = i;
            }
            if (i == 0) break; 
        }

        cout<<sum<<"\n";


    }

    return 0;
}