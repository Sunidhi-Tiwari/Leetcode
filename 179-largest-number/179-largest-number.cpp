class Solution {
public:
    
    
    static bool comp(int a, int b)
    {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }
    
    string largestNumber(vector<int>& nums) {
        
        string ans = "";
        if(nums.size() == 0) return ans;
        
        sort(nums.begin(), nums.end(), comp);
        for(int i=0; i<nums.size(); i++){
            ans += to_string(nums[i]);
        }
        return (ans[0] == '0') ? "0" : ans;
        
    }
};