class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
       
        int n = nums.size();
        vector<int> inc(n);
        vector<int> dec(n);
        vector<int> v;
        
        for(int i = 0; i<n; i++)
        {
            if(v.empty() || nums[i]>v.back())
            {
                v.push_back(nums[i]);
                inc[i] = v.size();
            }
            
            else
            {
                
                int ind = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
                v[ind] = nums[i];
                inc[i] = ind+1;
            }
        }
        
        v.clear();
        
         for(int i = n-1; i>=0; i--)
        {
            if(v.empty() || nums[i]>v.back())
            {
                v.push_back(nums[i]);
                dec[i] = v.size();
            }
            
            else
            {
                
                int ind = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
                v[ind] = nums[i];
                dec[i] = ind+1;
            }
        }
        
        int ans = 0;
        
        for(int i = 1; i<n-1; i++)
        {
           if(inc[i]>1 and dec[i]>1) 
            {
                ans = max(ans, inc[i] + dec[i] -1);
            }
            
        }
        
        
     return n - ans;
    }
};