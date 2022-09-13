class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int max_cnt=0;
        for(int i=0;i<s.length();i++){
            
            if(s[i]=='('){
                st.push(s[i]);
            }
            if(s[i]==')'){
                int size=st.size();
                max_cnt=max(max_cnt,size);
                while(!st.empty() && s[i]==')'){
                    
                    st.pop();
                    i++;
                    
                }
                
                
            }
        }
        return max_cnt;
    }
};