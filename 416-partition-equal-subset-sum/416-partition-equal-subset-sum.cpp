class Solution {
public:
    bool helper(vector<int>nums,int target,int ind, vector<vector<int>>&dp){
        if(target==0)return true;
        if(ind==0)return (nums[0]==target);
        if(dp[ind][target]!=-1)return dp[ind][target];
        bool not_take=helper(nums,target,ind-1,dp);
        bool take=false;
        if(nums[ind]<=target)take=helper(nums,target-nums[ind],ind-1,dp);
        
        return dp[ind][target]=take | not_take;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        
        if(sum%2!=0){
            return false;
        }
        
        else{
//             int target=sum/2;
//             vector<vector<bool>>dp(nums.size()+1,vector<bool>(target+1,false));
//             if(nums[0]<=target)dp[0][nums[0]]=true;
//             for(int i=0;i<nums.size();i++){
//                 dp[i][0]=true;
//             }
            
//             // return helper(nums,sum/2,nums.size()-1,dp);
//             for(int i=1;i<nums.size();i++){
//                 for(int j=1;j<=target;j++){
//                     bool take=false;
//                     bool not_take=dp[i-1][j];
//                     if(nums[i]<=target){
//                         take=dp[i-1][j-nums[i]];
//                     }
                    
//                     dp[i][j]= take || not_take;
//                 }
//             }
//             return dp[nums.size()-1][target];
               int n = nums.size();
                // vector<vector<bool>> dp(n+1, vector<bool>(sum/2+1, false));
                vector<bool>prev(sum/2+1,false);
                vector<bool>curr(sum/2+1,false);
                if(nums[0]<=sum/2){
                    prev[nums[0]]=true;
                }
                prev[0]=curr[0]=true;

                for(int index=1;index<n;index++){
                    for(int target=1;target<=sum/2;target++){
                        //if index is not selected
                        bool notTake = prev[target];

                        //if the index is selected
                        bool take = false;
                        if(target>=nums[index]){
                            take = prev[target-nums[index]];
                        }

                        curr[target] = take || notTake;
                    }
                    prev=curr;
                }

                return prev[sum/2];
        }
        return false;
    }
};