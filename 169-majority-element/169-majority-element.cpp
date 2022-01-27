class Solution {
public:
    int majorityElement(vector<int>& nums) {
//         map<int,int>m;
//         for(int i=0;i<nums.size();i++){
//             m[nums[i]]++;
            
//         }
//         for(auto it:m){
//             if(it.second>nums.size()/2){
//                 return it.first;
//             }
//         }
//         return 0;
        
        int i=1;
        int Majority_element=nums[0];
        int cnt=1;
        while(i<nums.size()){
            if(Majority_element==nums[i]){
                cnt++;
            }
            else{
                if(cnt==1){
                    Majority_element=nums[i];
                }
                else{
                    cnt--;
                }
            }
            i++;
        }
        return Majority_element;
        
    }
};