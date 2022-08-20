class Solution {
public:
    int helper(int i,vector<int>&nums,vector<int>&dp){
        if(i<0)return 0;
        if(i==0)return nums[i];
        if(dp[i]!=-1)return dp[i];
        int left=helper(i-1,nums,dp);
        int right=helper(i-2,nums,dp)+nums[i];
        
        return dp[i]= max(left,right);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return helper(nums.size()-1,nums,dp);
        
    }
};