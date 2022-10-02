class Solution {
public:
    int mod=1e9+7;
   long long  helper(int ind,int n,int k ,int target,vector<vector<int>>&dp){
        if(ind==n){
            if(target==0)return 1;
            else return 0;
        }
        if(target<0)return 0;
        if(dp[ind][target]!=-1)return dp[ind][target];
        long long  ans=0;
        for(int i=1;i<=k;i++){
            ans+=helper(ind+1,n,k,target-i,dp)%mod;
        }
        return dp[ind][target]=ans%mod;
        
    }
    int numRollsToTarget(int n, int k, int target) {
        int sum=0;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
       return  helper(0,n,k,target,dp);
       
    }
};