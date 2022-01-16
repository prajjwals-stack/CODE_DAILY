class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        int len = s.length();
        st.push('x');
        for(int i=0 ;i<len ;i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
                continue;
            } else {
                if(s[i] == ']' && st.top() == '[') {
                    st.pop();
                } else if(s[i] == '}' && st.top() == '{') { 
                    st.pop();
                } else if(s[i] == ')' && st.top() == '(') {
                    st.pop();
                }
                else return false;
            }
        }
        if(st.size() != 1) return false;
        return true;

        
    }
};