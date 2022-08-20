class Solution {
public:
    
    int rob(vector<int>& nums) {
        if(nums.size()==0)return 0;
        if(nums.size()==1)return nums[0];
        vector<int>dp(nums.size(),-1);
        dp[0]=nums[0];
        dp[1]=max(dp[0],nums[1]);
        
        
        for(int i=2;i<nums.size();i++){
            int take=dp[i-2]+nums[i];
            int not_take=dp[i-1];
            
            dp[i]=max(take,not_take);
        }
        return dp[nums.size()-1];
        
        
    }
};