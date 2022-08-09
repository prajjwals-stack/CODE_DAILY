class Solution {
public:
    vector<vector<int>>sol;
    
    void rec(int ind,int target,vector<int>& cand,vector<int>& v,int n){
        if(ind>=n || target==0){
            if(target==0){
                sol.push_back(v);
            }
            return;
        }
        
        for(int i=ind;i<n;i++){
            if(i!=ind && cand[i]==cand[i-1])continue;
            if(cand[i]>target)break;
            
            v.push_back(cand[i]);
            rec(i+1,target-cand[i],cand,v,n);
            v.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>v;
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        rec(0,target,candidates,v,n);
    
    
        return sol;
    }
};