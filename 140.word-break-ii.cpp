#include <string>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
class Solution {

private:
    bool checkword(string s, vector<string>& wordDict){
        for(auto wrd:wordDict){
            if(s==wrd) return true;
        }
        return false;
    }

    vector<string> getwords(string wrd,string rem, vector<string>& wordDict){
        if(rem.size()<1) return{};
        vector<string>subwords;
        vector<string>out;
        string space=" ";
        if(wrd=="") space="";
        for(int i=0;i<rem.size();i++){
            string subwrd=rem.substr(0,i), subrem=rem.substr(i,rem.size()-i);
            if(checkword(wrd,wordDict)){
                subwords=getwords(subwrd,subrem,wordDict);
                for(string word:subwords){out.push_back(wrd+space+word);}
            }
        }

        return subwords;
    }


public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        return getwords("",s,wordDict);
    }
};
// @lc code=end

