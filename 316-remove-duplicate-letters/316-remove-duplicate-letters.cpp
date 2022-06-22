class Solution {
public:
    
    
    string removeDuplicateLetters(string s) {
        
       int freq[26];
        
       for(int i = 0; i<26; i++) freq[i] = 0;
        
       bool vis[26];
       for(int i = 0; i<26; i++) vis[i] = false;
        
        
        for(int i = 0; i<s.length(); i++)
            freq[s[i] - 'a']++;
        
        string res = "";
         
        for(int i = 0; i<s.length(); i++)
        {
            freq[s[i] - 'a']--;
            
            if(!(vis[s[i]- 'a']))
            {
                while(res.size()>0 && res.back() > s[i] && freq[res.back()-'a'] > 0)
                {   
                    vis[res.back() - 'a'] = false;
                    res.pop_back();
                 
                }
                
                  vis[s[i] - 'a'] = true;
            res += s[i];
            
            }
            
          
        }
      
        
        return res;
    }
};