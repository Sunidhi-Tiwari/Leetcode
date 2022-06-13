class Solution {
public:
    int dp[301];
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        set<string> dict;
        for(auto a: wordDict) dict.insert(a);
        int n = s.size();
        
        dp[n] = 1;
        
        for(int i = n-1; i>=0; i--)
        {
            string temp;
            for(int j = i; j<n; j++)
            {
                temp += s[j];
                if(dict.find(temp) != dict.end() && dp[j+1])
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
        
        
        return dp[0];
        
        
    }
};