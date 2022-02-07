class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=0;
        int i=0,j=height.size()-1;
        while(i<j){
            maxi=max(maxi,min(height[i],height[j])*abs(i-j));
            if(height[i]>height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return maxi;
    }
};