class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
       
        
        vector<vector<int>> dp(m, vector<int> (m));
        
        for(int j = 0; j<m; j++)
            dp[m-1][j] = triangle[m-1][j];
        
 
        for(int i = m-2; i>=0; i--)
        {
            for(int j = i; j>=0; j--)
            {
               
                     int di = INT_MAX;
                     int dn = INT_MAX;
                     dn = triangle[i][j] + dp[i+1][j];
                     di = triangle[i][j] + dp[i+1][j+1];
                     dp[i][j] = min(dn,di);
                     
                
            }
        }
       
        return dp[0][0];
    }     
      
   
    

};