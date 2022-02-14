class Solution {
public:
    
    void dfs(string s, string e, double tmp, double &ans, map<string,vector<pair<string,double>>>&m, set<string>&vis){
        if(vis.find(s)!=vis.end())return;
        else{
            vis.insert(s);
            if(s==e){
                ans=tmp;
                return;
            }
            else{
                for(auto i:m[s]){
                    dfs(i.first,e,tmp*i.second,ans,m,vis);
                }
            }
        }
    }
   
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)     {
        map<string,vector<pair<string,double>>>m;
        
        
        for(int i=0;i<equations.size();i++){
            m[equations[i][0]].push_back({equations[i][1],values[i]});
            m[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }
        vector<double>res;
        
        for(int i=0;i<queries.size();i++){
            double ans=-1;
            set<string>vis;
            if(m.find(queries[i][0])!=m.end())
            dfs(queries[i][0],queries[i][1],1.0,ans,m,vis);
            res.push_back(ans);
       }
     return res;
        
    }
};