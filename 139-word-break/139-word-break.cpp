class Solution {
public:
    int dp[301];
    
    int f(int i, string &s, set<string> & dict)
    {
        if(i == s.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        
        string temp;
        
        for(int j = i; j<s.size(); j++)
        {   
            temp += s[j];
            if(dict.find(temp) != dict.end())
            {
                if(f(j+1, s, dict)) return dp[i] = 1;
            }
        }
        
        return dp[i] = 0;
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        set<string> dict;
        for(auto a: wordDict) dict.insert(a);
        memset(dp, -1, sizeof(dp));
        
        return f(0, s, dict);
        
        
    }
};