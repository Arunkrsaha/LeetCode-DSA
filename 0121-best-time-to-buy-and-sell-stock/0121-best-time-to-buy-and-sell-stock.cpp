class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int buyAtPrices= INT_MAX;
        int profit=0;
        
        for(int i=0;i<n;i++)
        {
            buyAtPrices=min(buyAtPrices,prices[i]);
            profit= max(profit, prices[i]-buyAtPrices);
        }
        return profit;
    }
};