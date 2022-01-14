class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        for(int i=0;i<ransomNote.length();i++){
            m1[ransomNote[i]]++;
        }
        for(int i=0;i<magazine.length();i++){
            m2[magazine[i]]++;
        }
        for(int i=0;i<ransomNote.length();i++){
           if(m1[ransomNote[i]]>m2[ransomNote[i]]){
               return false;
           }
        }
        return true;
    }
};