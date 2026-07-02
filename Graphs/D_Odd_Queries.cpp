#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){

        int n,q;
        long long sum=0;
        cin>>n>>q;
    
        vector <int> arr(n);
        vector<int>leftparity(n);
        vector<int>rightparity(n);


        for(int i=0;i<n;i++){
            cin>>arr[i];
            sum+=arr[i];
            if(sum%2==0) leftparity[i]=0;
            else leftparity[i]=1;
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=arr[i];
            if(sum%2==0) rightparity[i]=0;
            else rightparity[i]=1;
        }

        while(q--){
            int l,r,k;
            cin>>l>>r>>k;

            int segparity = ((r - l + 1) & 1) & (k & 1);
            int newparity;
            if((l-2)>=0 && r<n){  newparity=leftparity[l-2] ^ segparity ^ rightparity[r];}
            else if((l-2)>=0 && r>=n) { newparity=leftparity[l-2] ^ segparity;}
            else if ((l-2)<0 && r<n) { newparity= segparity ^ rightparity[r];}
            else { newparity= segparity;}

            if(newparity==1) cout<<"YES\n";
            else cout<<"NO\n";
        }


    }



    return 0;
}