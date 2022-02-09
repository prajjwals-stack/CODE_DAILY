class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        }
        
        int prev=nums[1]-nums[0];
        int cnt;
        if((nums[1]-nums[0])!=0){
            cnt=2;
        }
        else{
            cnt=1;
        }
        for(int i=2;i<nums.size();i++){
            int curr=nums[i]-nums[i-1];
            if((prev>=0 && curr<0) || (prev<=0 && curr>0)){
                cnt++;
                prev=curr;
            }
        }
        return cnt;
    }
};