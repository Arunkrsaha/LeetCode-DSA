class Solution {
public:
    int MOD = 1e9+7;
    vector<vector<int>> edges;
    vector<vector<int>> memo;
    
    int knightDialer(int N) {
        int ans = 0;
        edges = vector<vector<int>>(10);

        edges[0] = {4,6};
        edges[1] = {6,8};
        edges[2] = {7,9};
        edges[3] = {4,8};
        edges[4] = {3,9,0};
        edges[5] = {};
        edges[6] = {1,7,0};
        edges[7] = {2,6};
        edges[8] = {1,3};
        edges[9] = {2,4};
        
        vector<vector<int>> dp(2, vector<int>(10, 0));
        
        for(int n = 0; n < N; n++){
            for(int cur = 0; cur <= 9; cur++){
                if(n == 0){
                    dp[n%2][cur] = 1;
                }else if(n == 1){
                    dp[n%2][cur] = edges[cur].size();
                }else{
                    dp[n%2][cur] = 0;
                    for(int nei : edges[cur]){
                        dp[n%2][cur] = (dp[n%2][cur] + dp[(n-1)%2][nei]) % MOD;
                    }
                }
            }
        }
        
        for(int cur = 0; cur <= 9; cur++){
            ans = (ans + dp[(N-1)%2][cur]) % MOD;
        }
        
        return ans;
    }
};