#include <iostream>
#include <vector>

using namespace std;
static const int MOD=1e9+7;

int ways(int n,int m,vector<int>&arr,vector<int>&ind,int st){

    if(ind[st]==-1) return 1;
    if( (ind[st]==0 && abs(arr[0]-arr[1])>1) || (ind[st]==n-1 && abs(arr[n-1]-arr[n-2])>1) )return 0;
    if ( abs(arr[ind[st]]-arr[ind[st]-1])>1 || abs(arr[ind[st]]-arr[ind[st]+1])>1 ) return 0;
    

    int way=0;
    int indcnt=0;
    for(int i:ind){

        for(int j=1;j<=m;j++){
            arr[i]=j;
            way+=ways(n,m,arr,ind,indcnt+1);
        }
        indcnt++;
    }


    return way;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    vector<int>arr;
    vector<int>ind;
    for(int i=0;i<n;i++){cin>>arr[i];if(arr[i]==0) ind.push_back(i);}
    ind.push_back(-1);

    cout<<ways(n,m,arr,ind,0);


    return 0;
}