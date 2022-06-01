class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum=0;
        int i=0;
        vector<int>ans;
        while(i<nums.size()){
            sum+=nums[i];
            ans.push_back(sum);
            i++;
        }
        return ans;
    }
};