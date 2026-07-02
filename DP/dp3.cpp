#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/*
int sum(int x, vector<int>& coins,vector<int>& dp) {

    if (x == 0) return 0;
    if (x < 0) return INT_MAX;
    if(dp[x]!=-1) return dp[x];

    int ans = INT_MAX;

    for (int c : coins) {
        int sub = sum(x - c, coins,dp);

        if (sub != INT_MAX) {  // prevent overflow
            ans = min(ans, 1 + sub);
        }
    }
    dp[x]=ans;
    return ans;
}

int main() {
    int n,x;
    cin>>n>>x;

    vector<int>coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];

    vector<int>dp(x+1,-1);

    int result = sum(x,coins,dp);

    if (result == INT_MAX)
        cout << "Not possible";
    else
        cout << result;

    return 0;
}
*/


//TABULATION
int main()
{
    int n,x;
    cin>>n>>x;

    vector<int>coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];

    vector<int>dp(x+1,INT_MAX);
    dp[0]=0;

    for(int i=0;i<=x;i++){
        for(int c:coins){
            if(i-c>=0 && dp[i-c]!=INT_MAX){
                dp[i]=min(dp[i],1+dp[i-c]);
            }
        }
    }
    
    if(dp[x]==INT_MAX) cout<<-1;
    else cout<<dp[x]<<endl;

    return 0;

}