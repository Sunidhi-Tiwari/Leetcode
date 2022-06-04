class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++)
            sum += nums[i];
        
        if(sum-target<0 || (sum-target)%2) return 0;
        
        int tar = (sum-target)/2;
        
        vector<vector<int>> dp(n, vector<int>(tar+1,0));
        
        if(nums[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        
        if(nums[0] != 0 && nums[0]<=tar) dp[0][nums[0]] = 1;
        
        for(int i = 1; i<n; i++)
        {
            for(int t = 0; t<=tar; t++)
            {
                int nottake = dp[i-1][t];
                int take = 0;
                if(nums[i] <= t) take = dp[i-1][t-nums[i]];
                
                dp[i][t] = nottake + take;
            }
        }
        
    
        
        return dp[n-1][tar];
        
        
    }
    
};
    
//     int f(int ind, int tar, vector<int>& nums,  vector<vector<int>> &dp)
//     {
//         if(ind == 0)
//         {
//             if(nums[0] == 0 && tar == 0) return 2;
//             if(tar == 0 || nums[0] == tar) return 1;
//             return 0;
//         }
        
//         if(dp[ind][tar] != -1) return dp[ind][tar];
        
//         int nottake = f(ind-1, tar, nums, dp);
            
//         int take = 0;
        
//         if(nums[ind]<=tar) take = f(ind-1, tar-nums[ind], nums, dp);
            
//         return dp[ind][tar] = nottake + take;
//     }
