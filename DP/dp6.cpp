#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;
static const int MOD = 1e9 + 7;


int getDigitAtIndex(int number, int index) {
    int count = 0;
    while (count < index) {
        number /= 10; 
        count++;
    }
    return number % 10; 
}

int cnt(int n, vector<int> &dp){
    if(n==0) return 0;
    if(n<0) return INT_MAX;
    if(dp[n]!=INT_MAX) return dp[n];

    int len=(to_string(n)).length();

    int steps=INT_MAX;
    for(int i=0;i<len;i++){
        int digit=getDigitAtIndex(n,len-1-i);
        if(digit!=0){
            int nxtstep=cnt( n-digit, dp);
            if(nxtstep!=INT_MAX) steps=min(steps,1+nxtstep);
        }
    }

    dp[n]=steps;
    return dp[n];

}

int main(){

    int n;
    cin>>n;

    vector<int>dp(n+1,MOD);
    //cout<<cnt(n,dp);

    //TABULATION
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int steps=MOD;
        int len=(to_string(i)).length();
        for(int j=0;j<len;j++){
            int digit=getDigitAtIndex(i,j);
            int nxtstep=dp[i-digit];
            if(digit!=0 && nxtstep!=MOD) steps=min(steps,1+nxtstep);
        }
        if(steps!=MOD) dp[i]=steps;
    }

    cout<<dp[n];

    return 0;
}

/*
You are given an integer n. On each step, you may subtract one of the digits from the number.
How many steps are required to make the number equal to 0?
Input
The only input line has an integer n.
Output
Print one integer: the minimum number of steps.
Constraints

1 \le n \le 10^6

Example
Input:
27

Output:
5

Explanation: An optimal solution is 27 \rightarrow 20 \rightarrow 18 \rightarrow 10 \rightarrow 9 \rightarrow 0
*/