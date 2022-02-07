class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt_a=0, cnt_b=0, cnt_c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                cnt_a++;
            }
            else if(nums[i]==1){
                cnt_b++;
            }
            else{
                cnt_c++;
            }
        }
        for(int i=0;i<cnt_a;i++){
            nums[i]=0;
        }
        for(int i=cnt_a;i<cnt_a+cnt_b;i++){
            nums[i]=1;
        }
        for(int i=cnt_a+cnt_b;i<cnt_a+cnt_b+cnt_c;i++){
            nums[i]=2;
        }
    }
};