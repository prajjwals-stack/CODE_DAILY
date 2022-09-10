class Solution {
public:
    
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0))); 
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int tran=1;tran<=k;tran++){
                            if(j){
                                    dp[i][j][tran]=max( (-prices[i]+dp[i+1][0][tran]) ,      dp[i+1][1][tran] );
                                }
                                else{
                                    dp[i][j][tran]=max( (prices[i]+dp[i+1][1][tran-1]) ,  dp[i+1][0][tran]);
                                }
         
                }
            }
        }
        return dp[0][1][k];
    }
};