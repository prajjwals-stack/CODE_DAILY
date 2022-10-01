class Solution {
public:
    int helper(int ind,string &s, vector<int>&dp){
        if(ind==s.size())return 1;
        if(ind>s.size())return 0;
        
        if(dp[ind]!=-1)return dp[ind];
        if(s[ind]=='0')return dp[ind]=0;
        
        int one=helper(ind+1,s,dp);
        int two=0;
        if(ind<s.size()-1 && stoi(s.substr(ind, 2)) >= 0 && stoi(s.substr(ind, 2)) <= 26){
            two=helper(ind+2,s,dp);
        }
        return dp[ind]=one+two;
        
    }
    int numDecodings(string s) {
        if(s[0]=='0')return 0;
        vector<int>dp(s.size(),-1);
        int ind=0;
        return helper(ind,s,dp);
    }
};