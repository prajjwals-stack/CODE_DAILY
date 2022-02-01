class Solution {
public:
    int maxProfit(vector<int>& p) {
        int MaxProfit=0;
        int BuyPrice=p[0];
        for(int i=0;i<p.size();i++){
            BuyPrice=min(BuyPrice,p[i]);
            MaxProfit=max(MaxProfit,p[i]-BuyPrice);
        }
        return MaxProfit;
        
    }
};