#include <iostream>
#include <vector>

using namespace std;
static const int MOD=1e9+7;

int mxpage(int i, int money, vector<int>& pg, vector<int>& pr,vector<vector<int>>&dp){
    //No more books to consider or no money left
    if (i<0 || money<=0) return 0;
    if(dp[i][money]!=-1) return dp[i][money];
    //Skip this book
    int res=mxpage(i-1,money,pg,pr,dp)%MOD;
    //Take this book (if we can afford it)
    if (money>=pr[i]) {
        res=max(res, (pg[i]+mxpage(i-1,money-pr[i],pg,pr,dp))%MOD );
    }
    dp[i][money]=res;
    return res;
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n,x;
    cin>>n>>x;

    vector<int>pr(n);
    vector<int>pg(n);
    //vector<vector<int>>dp(n,vector<int>(x+1,-1));

    for(int i=0;i<n;i++) cin>>pr[i];
    for(int i=0;i<n;i++) cin>>pg[i];

    //cout<<mxpage(n-1,x,pr,pg,dp);

    
    //TABULATION------------------------------------------------------------
    vector<int> dp(x + 1, 0);
    //Iterate through each book
    for (int i = 0; i < n; i++) {
        int cost = pr[i];
        int pages = pg[i];
        // Step 2: Iterate through the money BACKWARDS
        // This ensures we don't use the SAME book 'i' more than once.
        for (int j = x; j >= cost; j--) {
            // Decision: Max of (keeping current pages, or buying new book)
            dp[j] = max(dp[j], dp[j - cost] + pages);
        }
    }
    cout << dp[x] << endl;

    return 0;
}