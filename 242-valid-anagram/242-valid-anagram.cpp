class Solution {
public:
    bool isAnagram(string s1, string s2) {
        
       
          if( s2.length() != s1.length() ) return false;
        
        vector<int> arr(26);
        vector<int> cur(26);
        
        for(int i = 0; i<26; i++) arr[i] = 0;
        for(int i = 0; i<26; i++) cur[i] = 0;
        
        for(int i = 0; i<s1.length(); i++)
            arr[s1[i] - 'a']++;
        
         for(int i = 0; i<s1.length(); i++)
            cur[s2[i] - 'a']++;
       
         if(cur == arr) return true;
        
        return false;
        
    }
};