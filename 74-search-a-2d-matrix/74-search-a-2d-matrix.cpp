class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i<matrix.size(); i++){
            int l=0;
            int r=matrix[0].size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(target>matrix[i][mid]){
            l=mid+1;
            }
            else if(target<matrix[i][mid]){
            r=mid-1;
            }
            else if(target==matrix[i][mid]){
            return true;
            }
        }
        }
            return false;
    }
};