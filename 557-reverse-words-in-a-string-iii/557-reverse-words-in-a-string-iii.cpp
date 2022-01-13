class Solution {
public:
    string reverseWords(string s) {
        int p=0,q;
        for(int i=0;i<s.length()+1;i++){
            if(i==s.length() || s[i]==' '){
                q=i-1;
            while(p<q){
                swap(s[p++],s[q--]);
            
            }
                p=i+1;
        }
        }
        return s;
        
    }
};