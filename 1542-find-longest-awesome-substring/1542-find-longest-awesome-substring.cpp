class Solution {
public:
    int longestAwesome(string s) {
        
        map<int,int> mp;
        
        int mask = 0;
        int ans = 0;
        mp[0] = -1;
        
        for(int i = 0; i<s.length(); i++)
        {
            mask = (mask^(1<<(s[i]-'0')));
            
            if(mp.find(mask) != mp.end())
                ans = max(ans, i-mp[mask]);
            
            for(int j = 0; j<=9; j++)
            {
                int newmask = (mask^(1<<j));
                 if(mp.find(newmask) != mp.end())
                 ans = max(ans, i-mp[newmask]);
            }
        
        
        if(mp.find(mask) == mp.end())
            mp[mask] = i;
        }
        return ans;
        
       
    }
    
    
};