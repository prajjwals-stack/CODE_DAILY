class Solution {
public:
    string pushDominoes(string d) {
        queue<pair<int,char>>q;
        for(int i=0;i<d.size();i++){
            if(d[i]!='.'){
                q.push({i,d[i]});
            }
        }
        while(q.empty()==false){
            int ind=q.front().first;
            char domino=q.front().second;
            q.pop();
            
            if(domino=='L' && ind>0 && d[ind-1]=='.'){
                d[ind-1]='L';
                q.push({ind-1,'L'});
            }
            else if(domino=='R' && ind<d.size()-1 && d[ind+1]=='.'){
                if(ind+2<d.size() && d[ind+2]=='L'){
                    q.pop();
                }
                else{
                     d[ind+1]='R';
                    q.push({ind+1,'R'});
                }
        }
    }
        return d;
    }
};