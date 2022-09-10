class Solution {
public:
    int helper(int ind,vector<int>& prices,int buy,int size,vector<vector<vector<int>>>&dp,int transaction){  //flag tell if we can buy or not
        if(ind==size || transaction==0){
            return 0;
        }
        if(dp[ind][buy][transaction]!=-1){
            return dp[ind][buy][transaction];
        }
        long profit=0;
        if(buy){
            profit=max((-prices[ind]+helper(ind+1,prices,0,size,dp,transaction)),(0+helper(ind+1,prices,1,size,dp,transaction)));
        }
        else{
            profit=max((prices[ind]+helper(ind+1,prices,1,size,dp,transaction-1)),(0+helper(ind+1,prices,0,size,dp,transaction)));
        }
        return dp[ind][buy][transaction]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int ind=0;
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1))); 
        return helper(ind,prices,1,n,dp,2);
    }
};