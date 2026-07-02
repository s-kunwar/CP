#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];


        vector <int> effect(n);

        effect[0]=abs(arr[0]-arr[1]);
        effect[n-1]=abs(arr[n-2]-arr[n-1]);

        int maxeffectind;
        if(effect[0]>effect[n-1]) maxeffectind=0;
        else maxeffectind=n-1;

        for(int i=1;i<n-1;i++){
            int ogdist=abs(arr[i-1]-arr[i])+abs(arr[i]-arr[i+1]);
            int newdist=abs(arr[i-1]-arr[i+1]);
            effect[i]=ogdist-newdist;
            if(effect[i]>effect[maxeffectind]) maxeffectind=i;
        }

        int x,y;
        if(maxeffectind==0){x=1;y=n-1;}
        else if(maxeffectind==n-1){x=0;y=n-2;}
        else{x=0;y=n-1;}
        
        int time=0;

        for(int i=x;i<y;i++){
            if(i==maxeffectind-1 && maxeffectind!=n-1){
                time+=abs(arr[i]-arr[i+2]);
            }
            else if(i==maxeffectind){
                continue;
            }
            else{
                time+=abs(arr[i]-arr[i+1]);
            }
        }

        cout<<time<<endl;


    }

    return 0;
}