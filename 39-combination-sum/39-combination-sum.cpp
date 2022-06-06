class Solution {
    
    void f(int ind, int target, vector<int>& candidates, vector<vector<int>> & ans, vector<int> &ds)
    {   
        if(target<0) return;
        
        if(ind == candidates.size())
        {
            if(target == 0)
                ans.push_back(ds);
            return;
        }
        
        if(candidates[ind] <= target)
        {
            ds.push_back(candidates[ind]);
            f(ind, target-candidates[ind], candidates, ans, ds);
            ds.pop_back();
        }
        
         f(ind + 1, target, candidates, ans, ds);
    }
    
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> ds;
        
        f(0, target, candidates, ans, ds);
        
        return ans;
    }
};