class Solution {
public:
    
    
          int lower_bound(vector<int>&v, int x)
	{
        int lo = 0, hi = v.size() - 1;
		while(lo<=hi)
		{
			int mid = lo + (hi-lo)/2;
			if(v[mid] >= x){
				hi = mid - 1;
			}
			else
				lo = mid + 1;
		}
		return lo;
	}
	
    int minimumMountainRemovals(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> inc(n), dec(n), v;
		
        for(int i = 0; i < nums.size(); i++)
        {
            if(v.empty() or nums[i] > v.back())
            {
                v.push_back(nums[i]);
                inc[i] = v.size();  
            }                       
            else
            {
                // find the index of smallest number which is >= nums[i] using Binary Search
                int index = lower_bound(v, nums[i]);
                
                inc[i] = index+1;
                v[index] = nums[i];
            }
        }
        
        
        v.clear();
       
        for(int i = n - 1; i >= 0; i--)
        {
            if(v.empty() or nums[i] > v.back())
            {
                v.push_back(nums[i]);
                dec[i] = v.size();   
            }                        
            else
            {
                // find the smallest number which is >= nums[i] using Binary Search
                int index = lower_bound(v, nums[i]);
                
                dec[i] = index + 1;
                v[index] = nums[i];
            }
        }

        int mx = 0;
        for(int i=1; i<nums.size()-1; i++) 
        {
            if(inc[i]>1 and dec[i]>1) 
            {
                int ans = inc[i]+dec[i]-1;
                mx = max(mx, ans);
            }
        }
        return nums.size() - mx;
        
    }
};