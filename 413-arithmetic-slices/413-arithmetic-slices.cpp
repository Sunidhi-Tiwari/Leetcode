class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n<=2) return 0;
        
        int prev = 0;
        int cur = 0;
        
        if(nums[2]-nums[1] == nums[1] - nums[0]) prev = 1;
        
        int ans = prev;
        
        for(int i = 3; i<n; i++)
        {
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2])
            {cur = 1 + prev;
             prev = cur;
             }
            else prev = 0;
            
            ans += prev;
            
           
        }
        
       
        return ans;
    }
};