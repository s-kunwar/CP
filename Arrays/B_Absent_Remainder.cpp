#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        vector<int>arr(n);
        int min=0;
        for(int i=0;i<n;i++){cin>>arr[i]; if(arr[i]<arr[min]) min=i;}

        int m=0;
        int ind=0;
        while(m<(n/2)){
            if(min==ind){ind++;continue;}
            cout<<arr[ind]<<' '<<arr[min]<<endl;
            m++;
            ind++;
        }

    }

    return 0;
}