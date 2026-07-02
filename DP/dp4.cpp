#include <iostream>
#include <vector>
#include <climits>

using namespace std;
static const int MOD = 1e9 + 7;

/*

Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ways you can produce a money sum x using the available coins.
For example, if the coins are \{2,3,5\} and the desired sum is 9, there are 8 ways:

2+2+5
2+5+2
5+2+2
3+3+3
2+2+2+3
2+2+3+2
2+3+2+2
3+2+2+2

Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
Output
Print one integer: the number of ways modulo 10^9+7.

*/



int main(){

    int n,x;
    cin>>n>>x;

    vector<int>coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];


    vector<int>dp(x+1,0);
    dp[0]=1 ;//exactly one way-taking no elements at all

    for(int i=1;i<=x;i++){

        int ways=0;
        for(int c :coins){
            if( i-c>=0) ways=(ways+dp[i-c])%MOD;
        }
        dp[i]=ways;
    }

    cout<<dp[x];

    return 0;
}