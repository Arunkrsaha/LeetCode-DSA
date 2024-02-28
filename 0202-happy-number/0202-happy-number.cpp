class Solution {
public:
    int squareSum(int n)
    {
        int sum=0;
        while(n)
        {
            sum+=(n%10)*(n%10);
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        set<int> s;
        s.insert(n);
        int square=n;
        while(1)
        {
            square= squareSum(square);
            if(square==1)
            {
                return true;
            }
            else if(s.find(square) != s.end())
            {
                return false;
            }
            s.insert(square);
        }
    }
};