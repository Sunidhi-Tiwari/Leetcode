class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
        
        vector<int> ans;
          if( s2.length() < s1.length() ) return ans;
        
        vector<int> arr(26);
        vector<int> cur(26);
        
        for(int i = 0; i<26; i++) arr[i] = 0;
        for(int i = 0; i<26; i++) cur[i] = 0;
        
        for(int i = 0; i<s1.length(); i++)
            arr[s1[i] - 'a']++;
        
         for(int i = 0; i<s1.length(); i++)
            cur[s2[i] - 'a']++;
       
         if(cur == arr) ans.push_back(0);
        
        for(int i = s1.length(); i< s2.length(); i++)
        {
            cur[s2[i - s1.length()] - 'a']--;
            cur[s2[i] - 'a']++;
            
            if(cur == arr) ans.push_back(i-s1.length()+1);
        }
       
       return ans;
        
    }
};