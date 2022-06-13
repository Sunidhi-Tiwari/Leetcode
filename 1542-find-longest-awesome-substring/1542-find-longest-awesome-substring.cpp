class Solution {
public:
    int longestAwesome(string s) {
        
//         unordered_map<int,int> mp;
        
//         int mask = 0;
//         int ans = -1e9;
//         mp[0] = -1;
        
//         for(int i = 0; i<s.length(); i++)
//         {
//             mask = (mask^(1<<(s[i]-'0')));
            
//             if(mp.find(mask) != mp.end())
//                 ans = max(ans, i-mp[mask]+1);
            
//             for(int j = 0; j<=9; i++)
//             {
//                 int newmask = (mask^(1<<j));
//                  if(mp.find(newmask) != mp.end())
//                  ans = max(ans, i-mp[newmask]+1);
//             }
        
        
//         if(mp.find(mask) == mp.end())
//             mp[mask] = i;
//         }
//         return ans;
        
         int ans = 0;
        int mask = 0;
 
        map <int, int> m;
 
        m[0] = -1;
 
        for (int i = 0; i < s.length(); i++) {
 
            mask ^= 1 << (s[i] - '0');
 
            if(m.find(mask) != m.end()) {
                ans = max(ans, i - m[mask]);
            }
 
            for (int d = 0; d <= 9; d++) {
                int new_mask = (mask ^ (1 << d));
                if(m.find(new_mask) != m.end()) {
                    ans = max(ans, i - m[new_mask]);
                }
            }
 
            if(m.find(mask) == m.end()) 
                m[mask] = i;
 
        }
 
        return ans;
    }
    
    
};