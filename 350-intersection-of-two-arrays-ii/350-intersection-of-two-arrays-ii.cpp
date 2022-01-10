class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        //if only 1 element is present
        
        if(nums1.size()==1 && nums2.size()==1){
            if(nums1[0]==nums2[0]){
                return  { nums1[0]};
            }
            else return {};
        }
        vector<int>v;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                v.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else{
                i++;
            }
        }
        return v;
    
    
    }
};