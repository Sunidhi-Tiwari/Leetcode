class Solution {
public:
    
    int f(int i, vector<int>& nums,  vector<int> &dp)
    {
        if(i == 0) return nums[0];
        if(i<0) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        return dp[i] = max(nums[i] + f(i-2, nums, dp), f(i-1, nums, dp));
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n,-1);
        
        return f(n-1, nums, dp);
        
    }
};