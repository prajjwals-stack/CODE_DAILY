class Solution {
public:
    
    vector<vector<int>>vv;
    
    void recursion(int ind,int target,vector<int>&v,vector<int>& candidates,int n){
        if(ind==n){
            if(target==0){
                vv.push_back(v);
            }
            return;
        }
        if(candidates[ind]<=target){
        v.push_back(candidates[ind]);
        
        recursion(ind,(target-candidates[ind]),v,candidates,n);
        v.pop_back();
        }
        recursion(ind+1,target,v,candidates,n);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>v;
        recursion(0,target,v,candidates,candidates.size());
        return vv;
        
    }
};