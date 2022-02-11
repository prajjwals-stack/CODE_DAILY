class Solution {
public:
    bool isColoredAlt(int V,vector<vector<int>>& graph,vector<int>& colored,int inode){
        queue<int>q;
        q.push(inode);
        colored[inode]=1;
        while(q.empty()==false){
            int node=q.front();
            q.pop();
            for(auto it: graph[node]){
                if(colored[it]==-1){
                    q.push(it);
                    colored[it]=1-colored[node];
                }
                else if(colored[it]==colored[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>colored(V+1,-1);
        for(int i=0;i<V;i++){
            if(colored[i]==-1){
                if(isColoredAlt(V,graph,colored,i)==false){
                    return false;
                }
            }
        }
        return true;
    }
};