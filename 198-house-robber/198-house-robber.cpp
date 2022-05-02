class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        int prev2 = nums[0];
        if(n == 1) return prev2;
        int prev1 = max(nums[0], nums[1]);
        
        
        if(n == 2) return prev1;
        
        int curi;
        
        for(int i = 2; i<n; i++)
        {
            int pick = nums[i] + prev2;
            int notpick = prev1;
            
            curi = max(pick, notpick);
            
            prev2 = prev1;
            prev1 = curi;
        }
       
        return curi;
    }
};