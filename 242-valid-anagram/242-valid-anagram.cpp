class Solution {
public:
    bool isAnagram(string s, string t) {
        bool result=true;
        if(s.length()!=t.length()){
            return false;
        }
        
        else{
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        for(int i=0;i<s.length();i++){
            m1[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            m2[t[i]]++;
        }
        for(int i=0;i<t.length();i++){
           if(m1[t[i]]!=m2[t[i]]){
               result=false;
           }
        }
        }
        return result;
        
        
    }
};