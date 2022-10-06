class TimeMap {
public:
    map<string,vector<pair<int,string>>>m;
    TimeMap() {
        m=map<string,vector<pair<int,string>>>();
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(m.find(key)!=m.end()){
            int start=0,end=m[key].size()-1;
            string ans="";
            while(start<=end){
                int mid=start+(end-start)/2;
                
                if(m[key][mid].first==timestamp) return m[key][mid].second;
                if(m[key][mid].first>timestamp) end=mid-1;
                else start=mid+1,ans=m[key][mid].second;

            }
            return ans;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */