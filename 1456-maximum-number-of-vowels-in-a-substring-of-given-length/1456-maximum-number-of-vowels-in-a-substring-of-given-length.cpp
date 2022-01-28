class Solution {
public:
    int maxVowels(string s, int k) {
        int max_vowel=0;
        int vowel=0;
        int i=0,j=0;
        while(j<s.size()){
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u'){
                vowel++;
            }
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                max_vowel=max(max_vowel,vowel);
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                vowel--;
                }
                i++;
                j++;
            }
        }
        return max_vowel;
    }
};