class Solution {
public:
    
    
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>m;
        for(int i=0;i<p.size();i++){
            m[p[i]]++;
        }
       
        
        int i=0,j=0;
        int k=p.size();
        vector<int>v;
        int count=m.size();
        while(j<s.size()){
            m[s[j]]--;
            if(m[s[j]]==0){
                count--;
            }
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(count==0){
                    v.push_back(i);
                }
                m[s[i]]++;
                if(m[s[i]]==1){
                    count++;
                }
                i++;
                j++;
            
            }
        }
        return v;
        
    }
};