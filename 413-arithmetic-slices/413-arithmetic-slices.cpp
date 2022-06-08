class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n<=2) return 0;
        
        long long int cnt = 0;
         long long int ans = 0;
        
        for(int i = 0; i<n-2; i++)
        {
            if(nums[i+2] - nums[i+1] == nums[i+1] - nums[i])
                cnt++;
            else
            {
                ans += (cnt*(cnt+1))/2;
                cnt = 0;
            }
        }
        
        if(cnt) ans +=  (cnt*(cnt+1))/2;
        return ans;
    }
};