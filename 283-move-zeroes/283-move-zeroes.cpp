class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p=0,q=0;
        while(p<=nums.size()-1){
            if(nums[p]==0 && nums[q]==0){
                p++;
            
            }
            else{
                swap(nums[p],nums[q]);
                p++;
                q++;
            }
        }
    }
};