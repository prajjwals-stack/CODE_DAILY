class Solution {
public:
    vector<vector<int>>ans;
    void helper(int ind, vector<int>& nums, int n,vector<int>&v){
        
            ans.push_back(v);
            
    
        for(int i=ind;i<n;i++){
            if(i!=ind && nums[i]==nums[i-1])continue;
            v.push_back(nums[i]);
            helper(i+1,nums,n,v);
            v.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n= nums.size();
        vector<int>v;
        sort(nums.begin(),nums.end());
        helper(0,nums,n,v);
        return ans;
    }
};