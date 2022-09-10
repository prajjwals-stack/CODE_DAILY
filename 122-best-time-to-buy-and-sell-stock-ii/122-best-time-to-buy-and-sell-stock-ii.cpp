class Solution {
public:
    int helper(int ind,vector<int>& prices,int buy,int size,vector<vector<int>>&dp){  //flag tell if we can buy or not
        if(ind==size){
            return 0;
        }
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        long profit=0;
        if(buy){
            profit=max((-prices[ind]+helper(ind+1,prices,0,size,dp)),(0+helper(ind+1,prices,1,size,dp)));
        }
        else{
            profit=max((prices[ind]+helper(ind+1,prices,1,size,dp)),(0+helper(ind+1,prices,0,size,dp)));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int ind=0;
        int n=prices.size();
         vector<vector<int>> dp(n,vector<int>(2,-1)); 
        return helper(ind,prices,1,n,dp);
        
    }
};