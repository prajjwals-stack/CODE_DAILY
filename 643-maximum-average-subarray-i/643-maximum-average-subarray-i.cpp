class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0,j=0;
        double sum=0;
        double Maxi=INT_MIN;
        while(j<nums.size()){
            sum+=nums[j];
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                Maxi=max(Maxi,sum/k);
                sum=sum-nums[i];
                i++;
                j++;
            }
        }
        return Maxi;
    }
};