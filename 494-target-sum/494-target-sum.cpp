class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++)
            sum += nums[i];
        
        if(sum-target<0 || (sum-target)%2) return 0;
        
        int tar = (sum-target)/2;
        
        vector<vector<int>> dp(n, vector<int>(tar+1,-1));
        
        
        int cnt = f(n-1, tar, nums, dp);
        
        return cnt;
        
        
    }
    
    int f(int ind, int tar, vector<int>& nums,  vector<vector<int>> &dp)
    {
        if(ind == 0)
        {
            if(nums[0] == 0 && tar == 0) return 2;
            if(tar == 0 || nums[0] == tar) return 1;
            return 0;
        }
        
        if(dp[ind][tar] != -1) return dp[ind][tar];
        
        int nottake = f(ind-1, tar, nums, dp);
            
        int take = 0;
        
        if(nums[ind]<=tar) take = f(ind-1, tar-nums[ind], nums, dp);
            
        return dp[ind][tar] = nottake + take;
    }
};