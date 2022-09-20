class Solution {
public:
    int ans=0;
    int helper(vector<int>& nums1, vector<int>& nums2,int i,int n,int j, int m,vector<vector<int>>&dp){
        if(i>=n || j>=m){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        helper(nums1,nums2,i+1,n,j,m,dp);
        helper(nums1,nums2,i,n,j+1,m,dp);
        int cnt=0;
        if(nums1[i]==nums2[j]){
            cnt=1+helper(nums1,nums2,i+1,n,j+1,m,dp);
        }
        else{
            cnt=0;
        }
        ans=max(ans,cnt);
        return dp[i][j]=cnt;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        helper(nums1,nums2,0,n,0,m,dp);
        return ans;
    }
};