class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int buyPrice=prices[0];
        for(int i =0;i<prices.size();i++){
            buyPrice=min(buyPrice,prices[i]);
            maxprofit=max(maxprofit,prices[i]-buyPrice);
        }
        return maxprofit;
        
        
    }
};