class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();
        
        int slow = 0;
        int cur = 0;
        
        while(cur<n)
        {
            if(nums[cur] == 0)
            cur++;
            
            else
            {
                    swap(nums[cur], nums[slow]);
                    cur++; slow++;
            }
        }
        
        return;
        
    }
};