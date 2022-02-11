class Solution {
public:
    bool isColoredAltdfs(int V,vector<vector<int>>& graph,vector<int>& colored,int inode){
        if(colored[inode]==-1)colored[inode]=1;
        for(auto it: graph[inode]){
            if(colored[it]==-1){
                colored[it]=1-colored[inode];
                if(isColoredAltdfs(V,graph,colored,it)==false){
                    return false;
                }
                
            }
            else if(colored[it]==colored[inode]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>colored(V+1,-1);
        for(int i=0;i<V;i++){
            if(colored[i]==-1){
                if(isColoredAltdfs(V,graph,colored,i)==false){
                    return false;
                }
            }
        }
        return true;
    }
};