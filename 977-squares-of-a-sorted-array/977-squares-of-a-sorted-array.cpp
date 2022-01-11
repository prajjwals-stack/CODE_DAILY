class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int i=0,j=nums.size()-1;
        vector<int>v;
        while(i<=j){
            if(abs(nums[i])<abs(nums[j])){
                v.push_back(nums[j]*nums[j]);
                j--;
            }
            else{
                v.push_back(nums[i]*nums[i]);
                i++;
            }
        }
        reverse(v.begin(),v.end());
        return v;
    
    
    
    }
    
    
};