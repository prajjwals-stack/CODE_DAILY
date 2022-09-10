class Solution {
public:
    // int helper(int ind,vector<int>& prices,int buy,int size,vector<vector<vector<int>>>&dp,int transaction){  //flag tell if we can buy or not
    //     if(ind==size || transaction==0){
    //         return 0;
    //     }
    //     if(dp[ind][buy][transaction]!=-1){
    //         return dp[ind][buy][transaction];
    //     }
    //     long profit=0;
    //     if(buy){
    //         profit=max((-prices[ind]+helper(ind+1,prices,0,size,dp,transaction)),(0+helper(ind+1,prices,1,size,dp,transaction)));
    //     }
    //     else{
    //         profit=max((prices[ind]+helper(ind+1,prices,1,size,dp,transaction-1)),(0+helper(ind+1,prices,0,size,dp,transaction)));
    //     }
    //     return dp[ind][buy][transaction]=profit;
    // }
    int maxProfit(vector<int>& prices) {
       
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0))); 
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int tran=1;tran<=2;tran++){
                            if(j){
                                    dp[i][j][tran]=max( (-prices[i]+dp[i+1][0][tran]) ,      dp[i+1][1][tran] );
                                }
                                else{
                                    dp[i][j][tran]=max( (prices[i]+dp[i+1][1][tran-1]) ,  dp[i+1][0][tran]);
                                }
         
                }
            }
        }
        return dp[0][1][2];
    }
};