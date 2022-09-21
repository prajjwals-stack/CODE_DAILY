class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>v(nums.size(),0);
        vector<int>ans;
        int sum=0;
        for(int i=0;i<nums.size();i++){
             if(nums[i]%2==0){
                 v[i]=1;
                 sum+=nums[i];
             }
        }
        
        for(int i=0;i<queries.size();i++){
            int index=queries[i][1];
            int val=queries[i][0];
            if(v[index]==1){
                sum-=nums[index];
            }
            nums[index]+=val;
            if(nums[index]%2==0){
                sum+=nums[index];
                v[index]=1;
            }
            else{
                v[index]=0;
            }
            ans.push_back(sum);        
        }
        return ans;
    }
};