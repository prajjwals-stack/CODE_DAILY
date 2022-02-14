class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int,vector<pair<int,int>>>m;
        for(int i=0;i<times.size();i++){
            m[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int>dis(n+1,INT_MAX);
        dis[k]=0;
        queue<int>q;
        q.push(k);
        while(q.empty()==false){
            int node=q.front();
            q.pop();
            
            for(auto it:m[node]){
                int wt=dis[node]+it.second;
                cout<<wt<<" ";
                if(dis[it.first]>wt){
                    q.push(it.first);
                    dis[it.first]=wt;
                }
            }
        }
        for(int i=0;i<dis.size();i++){
            cout<<dis[i]<<"////";
        }
        int maxi=0;
        for(int i=1;i<dis.size();i++){
            maxi =max(dis[i],maxi);
        }
        if(maxi==INT_MAX)return -1;
        return maxi;
    }
};