class Solution {
public:
    int countGoodSubstrings(string s) {
        int i=0,j=0;
        map<char,int>m;
        int cnt=0;
        while(j<s.size()){
            m[s[j]]++;
            if(j-i+1<3){
                j++;
            }
            
            else if(j-i+1==3){
                if(m.size()==3){
                    cnt++;
                }
                
                m[s[i]]--;
                if(m[s[i]]==0){
                    m.erase(s[i]);
                    
                }
                i++;
                j++;
                
            }
        }return cnt;
        
    }
};