/*
Time limit: 1.00 s
Memory limit: 512 MB

Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
For example, if n=3, there are 4 ways:1+1+1
1+2
2+1
3

Input
The only input line has an integer n.
Output
Print the number of ways modulo 10^9+7.
Constraints

1 \le n \le 10^6

Example
Input:
3

Output:
4
*/


/*
// TOP DOWN METHOD(TOO MANY RECURSIVE CALLS FOR 1e7 like numbers)

#include <iostream>
#include <vector>

using namespace std;


static const int mod=1e9 + 7;


long long st(int n,vector<long long>&dp){
    if(n<0) return 0;
    if(n==0) return 1;
    if(dp[n]>-1) return dp[n];

    long long ways=0;
    for(int i=1;i<=6;i++){
        ways=(ways + st(n-i,dp))%mod;
    }
    dp[n]=ways;
    return ways;
}


int main(){
    int n=10;
    vector<long long>dp(n+1,-1);
    cout<<st(n,dp);
    return 0;
}
*/


//TABULATION (BOTTOM UP)
#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int dice = 1; dice <= 6; dice++) {
            if (i - dice >= 0) {
                dp[i] = (dp[i] + dp[i - dice]) % MOD;
            }
        }
    }

    cout << dp[n] << "\n";
    return 0;
}
