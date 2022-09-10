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
      
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1)); 
        
        dp[n][0]=0;
        dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                long profit=0;
                if(j){
                profit=max((-prices[i]+dp[i+1][0]),dp[i+1][1]);
                }
                 else{
                    profit=max((prices[i]+dp[i+1][1]),dp[i+1][0]);
                }
    
            dp[i][j]=profit;
            }
        }
                                
        return dp[0][1];
        
        
    }
};