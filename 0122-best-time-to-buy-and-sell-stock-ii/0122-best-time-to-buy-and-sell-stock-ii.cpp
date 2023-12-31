class Solution {
public:
    int checkConditions(int index, int buy,int n, vector<int>& prices, vector<vector<int>> &dp)
    {
        if(index==n)
        {
            return 0;
        }
        if(dp[index][buy] != -1) return dp[index][buy];
        int profit= 0;
        if(buy)
        {
            profit= max(-prices[index]+checkConditions(index+1,0,n,prices,dp),
                        0+checkConditions(index+1,1,n,prices,dp));
        }
        else
        {
            profit= max(prices[index]+checkConditions(index+1,1,n,prices,dp),
                        0+checkConditions(index+1,0,n,prices,dp));
        }
        return dp[index][buy]= profit;
    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return checkConditions(0, 1, n, prices, dp);
    }
};