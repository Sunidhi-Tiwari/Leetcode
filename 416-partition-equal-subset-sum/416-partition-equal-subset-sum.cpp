class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int sum = 0;
        
        for(int i = 0; i<n; i++)
            sum += nums[i];
        
        if(sum%2)
            return false;
        
        int k = sum/2;
        
        vector<bool> prev(k+1,0);
        vector<bool> cur(k+1,0);
        
        prev[0] = cur[0] = true;
        
        if(nums[0] <= k) prev[nums[0]] = true;
        
        for(int i = 1; i<n; i++)
        {
            for(int j = 1; j<=k; j++)
            {
                
                bool nottake = prev[j];
                bool take = false;
                if(nums[i] <= j) take = prev[j - nums[i]];
                cur[j] = nottake | take;
                
            }
            
            prev = cur;
        }
            
        return cur[k];
        
    }
};