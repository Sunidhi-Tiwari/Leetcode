class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
     
        int n = nums.size();
        vector< unordered_map<long long,int> > freq(n);
        
        int ans = 0;
        for(int i = 1; i<n; i++)
        {
            for(int j = 0; j<i; j++)
            {
            long long diff = (long long)nums[j] - (long long)nums[i];
            
            int cnt = (freq[j].count(diff)) ? freq[j][diff] : 0;
            freq[i][diff] += cnt + 1;
            ans += cnt;
            }
        }
        
        
     return ans;
        
    }
};