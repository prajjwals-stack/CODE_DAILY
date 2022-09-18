class Solution {
public:
    int trap(vector<int>& height) {

        int n=height.size();
        int maxR[n];
        int maxL[n];
        maxL[0]=height[0];
        for(int i=1;i<n;i++){
            maxL[i]=max(maxL[i-1],height[i]);
        }
        maxR[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            maxR[i]=max(maxR[i+1],height[i]);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=min(maxR[i],maxL[i])-height[i];
        }
        return sum;
        
        
    }
};