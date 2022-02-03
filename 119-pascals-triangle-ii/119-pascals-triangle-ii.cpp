class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0){
            return {1};
        }
        vector<int>v;
        v.push_back(1);
        long int res=1;
        for(int i=0;i<rowIndex-1;i++){
            
            res*=(rowIndex-i);
            res/=(i+1);
          
            v.push_back(res);
        }
        v.push_back(1);
        
        return v;
    }
};