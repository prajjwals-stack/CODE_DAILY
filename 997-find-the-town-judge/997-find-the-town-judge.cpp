class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>inDegree(n+1);
        vector<int>outDegree(n+1);
        for(int i=0;i<trust.size();i++){
            inDegree[trust[i][1]-1]++;
            outDegree[trust[i][0]-1]++;
        }
        for(int i=0;i<n;i++){
            if(inDegree[i]==n-1 && outDegree[i]==0){
                return i+1;
            }
    
        }
        return -1;
    }
};