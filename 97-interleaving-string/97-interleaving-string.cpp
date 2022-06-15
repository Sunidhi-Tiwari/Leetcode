class Solution {
public:
    
    
    bool isInterleave(string s1, string s2, string s3) {
        
        int n = s1.size();
        int m = s2.size();
        
        if(s3.length() != n+m) return false;
        
           vector<bool> prev(m+1,false);
           vector<bool> cur(m+1,false);
        
         prev[0] = true;
        
         for(int j = 1; j<=m; j++) if(s2[j-1] == s3[j-1] && prev[j-1] == true) prev[j] = true;
         
        
        for(int i = 1; i<=n; i++)
        {   
              if(s1[i-1] == s3[i-1] && prev[i-1] == true ) cur[0] = true;
            
                
            for(int j = 1; j<=m; j++)
            {
              cur[j] = (prev[j] && s1[i - 1] == s3[i + j - 1]) || (cur[j - 1] && s2[j - 1] == s3[i + j - 1]);
              
            }
            
            prev = cur;
        }
        
        return prev[m];    }
};