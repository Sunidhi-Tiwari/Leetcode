class Solution {
public:
    int longestAwesome(string s) {
        
        vector<int> dp(1024,s.length());
        
        int mask = 0;
        int ans = 0;
        
        dp[0] = -1;
        
        for(int i = 0; i<s.length(); i++)
        {
            mask ^= (1<<(s[i]-'0'));
            
            if(dp[mask] != s.length())
                ans = max(ans, i-dp[mask]);
            
            for(int j = 0; j<=9; j++)
            {
                int newmask = (mask^(1<<j));
                 if(dp[newmask] != s.length())
                 ans = max(ans, i-dp[newmask]);
            }
        
        
        if(dp[mask] == s.length()) 
            dp[mask] = i;
        }
        return ans;
        
       
    }
    
    
};