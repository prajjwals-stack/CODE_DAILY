class Solution {
public:
    vector<int> findOriginalArray(vector<int>& c) {
        sort(c.begin(),c.end());
        map<int,int>m;
        if(c.size()%2!=0)return {};
        vector<int>v;
        for(int i=0;i<c.size();i++){
            m[c[i]]++;
            
        }
        for(int i=0;i<c.size();i++){
            if(m[c[i]]==0)continue;
            if(m[c[i]*2]==0)return {};
            v.push_back(c[i]);
            m[c[i]]--;
            m[c[i]*2]--;
        }
        return v;
        

      
    }
};