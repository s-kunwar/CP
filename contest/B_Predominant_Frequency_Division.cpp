#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin>>n;

        vector<int> arr(n);
        int total1=0,total2=0,total3=0;

        for(int i=0;i<n;i++) {
            cin>>arr[i];
            if(arr[i] ==1) total1++;
            else if(arr[i]==2) total2++;
            else total3++;
        }

        int ones1=0,twos1=0, three1=0;
        bool ans=false;

        // for the 1st part 
        for(int i=0;i< n-2;i++) {
            if(arr[i]== 1) ones1++;
            else if(arr[i] == 2) twos1++;
            else three1++;

            if(ones1 >= twos1+three1) {
                int ones2 =0,twos2=0,three2 = 0;
                
                // first found, second part scan
                for(int j=i+1; j<n-1;j++) {
                    if(arr[j] ==1)ones2++;
                    else if(arr[j]==2) twos2++;
                    else three2++;

                    if(ones2+twos2>=three2) {
                        ans=true;
                        break;
                    }
                }
            }
            if(ans) break;
        }

        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}