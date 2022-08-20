class Solution {
public:
    int robHelp(vector<int>& nums) {
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
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>temp1,temp2;
        for(int i=0;i<n;i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        return max(robHelp(temp1),robHelp(temp2));
        
    }
};