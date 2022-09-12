class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        
        int i=0,j=tokens.size()-1;
        int score=0;
        int max_score=0;
        while(i<=j){
            if(power>=tokens[i]){
                score++;
                power-=tokens[i];
                i++;
                max_score=max(score,max_score);
            }
            else if(score>0 && power<tokens[i]){
                power+=tokens[j];
                score--;
                j--;
                
            }
            else break;
        }
        return max_score;
    }
};