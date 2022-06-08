class Solution {
public:
    
      int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
      vector<int> prev(m+1);
      vector<int> cur(m+1);
        
      
        for(int j = 0; j<=m; j++) prev[j] = 0;
        
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=m; j++)
            {
                if(text1[i-1] == text2[j-1]) cur[j] = 1 + prev[j-1];
                else cur[j] = max(prev[j], cur[j-1]);
                
            }
            
            prev = cur;
        }
        
        
        return prev[m];
      }
        
    
    int minInsertions(string s) {
        
        string revs = s;
        reverse(revs.begin(), revs.end());
        
        
        int len = longestCommonSubsequence(s,revs);
        
        return s.length() - len;
        
    }
};