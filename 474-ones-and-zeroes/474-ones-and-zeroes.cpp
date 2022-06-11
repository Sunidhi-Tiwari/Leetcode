class Solution {
public:
    
    int dp[601][101][101] = {};
    
    int f(int ind, vector<pair<int,int>>& cnt, int m, int n)
    {
        int sz = cnt.size();
        
        if(ind == sz or (m<0 and n<0)) return 0;
        
        if(dp[ind][m][n] != -1) return dp[ind][m][n];
        
        if(cnt[ind].first>m || cnt[ind].second>n) return f(ind+1, cnt, m, n);
            
        int pick = 1 + f(ind+1, cnt, m - cnt[ind].first, n - cnt[ind].second);
        
        int notpick = f(ind+1, cnt, m, n);
        
        return dp[ind][m][n] =  max(pick, notpick);
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        
        vector<pair<int,int>> cnt;
        memset(dp, -1, sizeof(dp));
        
        for(auto& s: strs)
        {   
            int one = 0; int zero = 0;
            for(auto j: s) (j == '0') ? zero++ : one++;
            cnt.push_back({zero, one});
        }
        
        return f(0, cnt, m, n);
        
    }
};