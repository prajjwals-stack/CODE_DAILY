class Solution {
public:
    vector<vector<int>>res;
    void recur(vector<int>& nums,vector<int>& ans,vector<int>& map){
        if(ans.size()==nums.size()){
            res.push_back(ans);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(map[i]==0){
            ans.push_back(nums[i]);
            map[i]=1;
            recur(nums,ans,map);
            ans.pop_back();
            map[i]=0;
        }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ans;
        vector<int>map(nums.size(),0);
        
        recur(nums,ans,map);
        return res;
    }
};