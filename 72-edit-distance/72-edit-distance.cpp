class Solution {
public:
    // tabulation
   
    int minDistance(string word1, string word2) {
        
        int n = word1.length();
        int m = word2.length();
        
        vector<int> prev(m+1,0);
        vector<int> cur(m+1,0);
        
        for(int j = 0; j<=m; j++) prev[j] = j;
        
        for(int i = 1; i<=n; i++)
        {     cur[0] = i;
              for(int j = 1; j<=m; j++)
              {
                  if(word1[i-1] == word2[j-1])
                      cur[j] = prev[j-1];
                  else
                      cur[j] = 1 + min({prev[j] , prev[j-1] , cur[j-1]});
              }
         
         prev = cur;
        }
        
        
        
        return prev[m];
    }
};