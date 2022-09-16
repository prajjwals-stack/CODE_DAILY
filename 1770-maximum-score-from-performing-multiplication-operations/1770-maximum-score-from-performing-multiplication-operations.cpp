class Solution {
public:
    int sum=0;
    int helper(vector<int>& nums, vector<int>& m,int indstartnum,int indendnum,int indstartm,int indendm, vector<vector<vector<int>>>&dp){
        if(indstartm==indendm+1){
            return 0;
        }
        if(dp[indstartm][indstartnum][indendnum]!=-1){
            return dp[indstartm][indstartnum][indendnum];
        }
        int profit=0;
        profit=max((nums[indstartnum]*m[indstartm]+helper(nums,m,indstartnum+1,indendnum,indstartm+1,indendm,dp)),
                   (nums[indendnum]*m[indstartm]+helper(nums,m,indstartnum,indendnum-1,indstartm+1,indendm,dp)));
        
        return dp[indstartm][indstartnum][indendnum]=profit;
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n=nums.size();
        int m=multipliers.size();
        vector<vector<int>>dp(m+1, vector<int>(m+1,0));
        
        
        for(int i=m-1;i>=0;i--){
            for(int j=i;j>=0;j--)
                {
                  int start=nums[j]*multipliers[i]+dp[i+1][j+1];
                  int end=nums[n-1-(i-j)]*multipliers[i]+dp[i+1][j];
                
                 dp[i][j]=max(start,end);
                }
            }
        
        return dp[0][0];
    
       
        
    }
};