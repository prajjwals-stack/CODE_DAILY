class Solution {
public:
    int sum=0;
    void helper(vector<int>&nums,int ind,int xor_sum){
        if(ind==nums.size()){
            sum+=xor_sum;
            return;
        }
        xor_sum=xor_sum^nums[ind];
        helper(nums,ind+1,xor_sum);
        xor_sum=xor_sum^nums[ind];
        helper(nums,ind+1,xor_sum);
    }
    int subsetXORSum(vector<int>& nums) {
        int xor_sum=0;
        helper(nums,0,xor_sum);
        return sum;
        
    }
};