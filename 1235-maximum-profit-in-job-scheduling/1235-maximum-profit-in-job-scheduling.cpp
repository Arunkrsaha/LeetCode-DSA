class Solution {
public:
    int n;
    int memo[50001];
    
    int getNext(vector<vector<int>> &array, int left, int currentJobEnd)
    {
        int right = n-1;
        int result = n+1;
        while(left<=right)
        {
            int mid = left+ (right-left)/2;
            if(array[mid][0]>=currentJobEnd)
            {
                result = mid;
                right = mid-1;
            }
            else
            {
                left= mid+1;
            }
        }
        return result;
    }
    
    int solve(vector<vector<int>> & array, int i)
    {
        if(i>=n)
        {
            return 0;
        }
        if(memo[i] != -1)
            return memo[i];
        int next = getNext(array, i+1, array[i][1]);
        
        int take = array[i][2] + solve(array, next);
        int notTake = solve(array, i+1);
        
        return memo[i] = max(take, notTake);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n= startTime.size();
        memset(memo, -1, sizeof(memo));
        vector<vector<int>> array(n, vector<int> (3,0)); // {start, end, profit}
        
        for(int i=0;i<n;i++)
        {
            array[i][0]= startTime[i];
            array[i][1]= endTime[i];
            array[i][2]= profit[i];
        }
        
        // Required to sort on yhe basis of staarting time
        auto comp = [&](auto& vec1, auto& vec2)
        {
            return vec1[0] <= vec2[0];
        };
        sort(begin(array), end(array), comp);
        
        return solve(array,0);
    }
};