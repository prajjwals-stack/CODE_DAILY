class Solution {
public:
    vector<int>rank;
    vector<int>parent;
    void makeset(){
        rank.resize(26);
        parent.resize(26);
        for(int i=0;i<26;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }
    void Union(int u,int v){
        u=findParent(u);
        v=findParent(v);
        if(rank[u]<rank[v]){
            parent[u]=v;
        }
        else if(rank[u]>rank[v]){
            parent[v]=u;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
    int findParent(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=findParent(parent[x]);
    }
    bool equationsPossible(vector<string>& e) {
        makeset();
        
        for(int i=0;i<e.size();i++){
            if(e[i][1]=='='){
                Union(e[i][0]-'a',e[i][3]-'a');
            }
        }
        for(int i=0;i<e.size();i++){
            if(e[i][1]=='!'){
                if(findParent(e[i][0]-'a')==findParent(e[i][3]-'a')){
                    return false;
                }
            }
        }
        return true;
        
        
    }
};