class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>q;
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
        }
        
        int max_product=1;
        for(int i=0;i<2 && !q.empty();i++){
            max_product=max_product*(q.top()-1);
            q.pop();
        }
        
        return max_product;
         
    }
};