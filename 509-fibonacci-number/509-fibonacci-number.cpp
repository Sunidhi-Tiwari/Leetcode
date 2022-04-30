class Solution {
public:
    int fib(int n) {
        
        
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        int prev2 = 0;
        int prev1 = 1;
        int curi;
        
        for(int i = 2; i<=n; i++)
        {
            curi = prev1 + prev2;
            prev2 = prev1;
            prev1 = curi;
        }
        
        return curi;
        
    }
};