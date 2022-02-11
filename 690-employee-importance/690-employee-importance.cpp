/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int,pair<int,vector<int>>>m;
    int bfs(int id,int sum){
        int ans=0;
        queue<int>q;
        q.push(id);
        while(q.empty()==false){
            int p=q.front();
            q.pop();
            ans+=m[p].first;
            for(auto it : m[p].second){
                q.push(it);
            }
        }
        return ans;
    }
    int getImportance(vector<Employee*> employees, int id) {
        
    
        for(auto i:employees){
            m[i->id]={i->importance,i->subordinates};
        }
        int sum=bfs(id,sum);
        return sum;
        
    }
};