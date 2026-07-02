#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){
        int n,notsame=0;
        cin>>n;
        vector <int> arr(n);

        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(i>0){
                if (arr[i]!=arr[i-1]) notsame=1;
            }
        }

        sort(arr.begin(),arr.end());
        if(notsame==0){cout<<-1<<endl;continue;}

        int j=0;
        vector<int>b;
        b.push_back(arr[j++]);
        while(j<n && arr[j]==arr[j-1]) b.push_back(arr[j++]);


        cout<<b.size()<<' '<<(arr.size()-b.size())<<endl;

        for(int bnum:b) cout<<bnum<<' ';
        cout<<endl;
        while(j<n) cout<<arr[j++]<<' ';
        cout<<endl;




    }

    return 0;
}