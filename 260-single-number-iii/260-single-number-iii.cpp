class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int n = nums.size();
        
        int res = 0;
        for(int i = 0; i<n; i++)
        {
            res ^= nums[i];
        }
        
        int bit = 0;
        for(int i = 0; i<32; i++)
        {
            if(res & (1<<i))
            {
                bit = i;
                break;
            }
        }
        
        int first = 0;
        
        for(int i = 0; i<n; i++)
        {
            if(nums[i] & (1<<bit))
                first = first^nums[i];
        }
        
        int second = first^res;
        
        return {first, second};
        
    }
};