class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int res=0;
        map<char,int>m;
        while(j<s.size()){
            m[s[j]]++;
            if(m.size()==j-i+1){
                res=max(res,j-i+1);
            }
            else if(m.size()<j-i+1){
                while(m.size()<j-i+1){
                    m[s[i]]--;
                    if(m[s[i]]==0){
                        m.erase(s[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return res;
    }
    
};