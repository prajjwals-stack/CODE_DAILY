class Solution {
public:
    void permutation(vector<int>& nums,vector<int>& sub,vector<vector<int>>&ans,vector<int>& vis){
        if(sub.size()==nums.size()){
            ans.push_back(sub);
            return;
        }
        for(int i =0;i<nums.size();i++){
            if(vis[i]==0){
                sub.push_back(nums[i]);
                vis[i]=1;
                permutation(nums,sub,ans,vis);
                sub.pop_back();
                vis[i]=0;
                
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>sub;
        vector<int>vis(nums.size(),0);
        
        
        permutation(nums,sub,ans,vis);
        return ans;
    }
};