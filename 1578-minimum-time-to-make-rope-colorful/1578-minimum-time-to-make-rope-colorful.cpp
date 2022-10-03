class Solution {
public:
    
    int minCost(string colors, vector<int>& neededTime) {
        int cost=0;
        priority_queue<int,vector<int>,greater<int>>pq; 
        for(int i=0;i<colors.size();i++){
            
            if(colors[i]!=colors[i+1]){
                pq.push(neededTime[i]);
                int size=pq.size();
                if(size==1){
                    pq.pop();
                }
                else{
                    
                    while(size>1){
                        cost+=pq.top();
                        pq.pop();
                        size--;
                    }
                    pq.pop();
                    
                }
            }
            else if(i+1<colors.size() && colors[i]==colors[i+1]){
                pq.push(neededTime[i]);
            }
        }
        return cost;
    }
};