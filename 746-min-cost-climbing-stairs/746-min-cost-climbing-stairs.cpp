class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        
        
        
        int prev1 = 0;
        int prev2 = 0;
        
        int curi;
        for(int i = 2; i<=n; i++)
        {
            curi = min({prev1 + cost[i-1], prev2 + cost[i-2]});
            
            prev2 = prev1;
            prev1 = curi;
        }
        
        return curi;
    }
};