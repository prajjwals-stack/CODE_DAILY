class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i=0,j=0;
        map<char,int>m;
        int k=p.size();
        for(int i=0;i<k;i++){
            m[p[i]]++;
        }
        int cnt=m.size();
        vector<int>v;
        while(j<s.size()){
            m[s[j]]--;
            if(m[s[j]]==0){
                cnt--;
            }
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(cnt==0)v.push_back(i);
                m[s[i]]++;
                if(m[s[i]]==1){
                    cnt++;
                }
                i++;
                j++;
                
            }
        }
        return v;
        
    }
};