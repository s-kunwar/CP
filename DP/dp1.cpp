#include <iostream>
#include <vector>

using namespace std;
using lng=long long ;


lng fib(lng n,vector<lng>&dp){

    if(dp[n]!=-1) return dp[n];
    else if(n==0) {dp[n]=0;return dp[n];}
    else if(n==1) {dp[n]=1;return dp[n];}
    else{
        dp[n]=fib(n-1,dp)+fib(n-2,dp);
        return dp[n];
    }

}



int main(){

    int n;
    cin>>n;
    vector<lng>dp(n+1,-1LL);
    
    for(int i=0;i<n;i++) cout<<fib(i,dp)<<' ';

    return 0;
}