class Solution {
public:
    void reverseS(vector<char>& s,int i){
        if(i>=s.size()/2){
            return ;
        }
        swap(s[i],s[s.size()-i-1]);
        reverseS(s,i+1);
    }
    void reverseString(vector<char>& s) {
        int i=0;
        reverseS(s,i);
    }
};