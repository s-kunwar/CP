#include <iostream>
#include <vector>

using namespace std;
static const int MOD=1e9+7;


int steps(int n,vector<string>& arr,int x,int y,vector<vector<int>>&dp){

    if(x>=n || y>=n || arr[x][y]=='*') return 0;
    if(x==n-1 && y==n-1) return 1;
    if(dp[x][y]!=-1) return dp[x][y];

    int ways=0;

    ways=(ways+steps(n,arr,x+1,y,dp))%MOD;
    ways=(ways + steps(n,arr,x,y+1,dp))%MOD;

    dp[x][y]=ways;
    return ways;

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(n,-1));
    cout<<steps(n,arr,0,0,dp);

    return 0;
}