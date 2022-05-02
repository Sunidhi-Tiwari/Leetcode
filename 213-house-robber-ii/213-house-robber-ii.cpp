class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        int prev2 = nums[0];
        if(n == 1) return prev2;
        
        int prev1 = max(nums[0], nums[1]);
        if(n == 2) return prev1;
        
        int curfi = prev1;
        
        for(int i = 2; i<n-1; i++)
        {
            int pick = nums[i] + prev2;
            int notpick = prev1;
            
            curfi = max(pick, notpick);
            
            prev2 = prev1;
            prev1 = curfi;
        }
       
         prev2 = nums[1];
         prev1 = max(nums[1], nums[2]);
 
        if(n == 3) return max(prev1, curfi);
        int curli;
        
        for(int i = 3; i<n; i++)
        {
            int pick = nums[i] + prev2;
            int notpick = prev1;
            
            curli = max(pick, notpick);
            
            prev2 = prev1;
            prev1 = curli;
        }
        
        return max(curfi,curli);
        
    }
};