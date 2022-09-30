class Solution {
public:
    void remove(int val,priority_queue<int>&pq){
        vector<int>v;
        while(pq.empty()==false && pq.top()!=val){
            v.push_back(pq.top());
            pq.pop();
        }
        pq.pop();
        for(int i=0;i<v.size();i++){
            pq.push(v[i]);
        }
        
    }
    // static bool cmp(pair<int,int>&a,pair<int,int>&b){
    //     if(a.first==b.first){
    //         return a.second>b.second;
    //     }
    //     return a.first>b.first;
    // }
    vector<vector<int>> getSkyline(vector<vector<int>>& B) {
        // map<int,int>m;
        vector<pair<int,int>>m;
        for(int i=0;i<B.size();i++){
            m.push_back({B[i][0],-B[i][2]});
            m.push_back({B[i][1],B[i][2]});
            // m[B[i][0]]=-B[i][2];
            // m[B[i][1]]=B[i][2];
        }
        sort(m.begin(),m.end());
        multiset<int, greater<int>> pq;
        // priority_queue<int>pq;
        pq.insert(0);
        vector<vector<int>>ans;
        int currentheight=0;
        
        for(auto it:m){
           
            if(it.second>0){
                pq.erase(pq.find(it.second));
            
                if( *pq.begin()!=currentheight){
                    ans.push_back({it.first,*pq.begin()});
                }
            }
            else{
                pq.insert(abs(it.second));
                if( *pq.begin()!=currentheight){
                    ans.push_back({it.first,*pq.begin()});
                }
            }
            currentheight=*pq.begin();
            
            
        }
        return ans;
    }
};