class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
       
        
        vector<vector<int>> dp(m, vector<int>(m,-1));
        
 
      /*  for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<=i; j++)
            {
                if(i == 0 && j == 0)
                    dp[i][j] = triangle[i][j];
              
                else 
                {   
                     int di = INT_MAX;
                     int dn = INT_MAX;
                     if(j<i)di = triangle[i][j] + dp[i-1][j];
                     if(j>0) di = triangle[i][j] + dp[i-1][j-1];
                     dp[i][j] = min(dn,di);
                     
                }
            }
        }*/
       
        return f(0,0,m,triangle,dp);
    }     
      
    
    int f(int i, int j, int m, vector<vector<int>>& triangle, vector<vector<int>>& dp)
    {
        if(i == m-1) return triangle[i][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int dn = triangle[i][j] + f(i+1,j,m,triangle,dp);
        int di = triangle[i][j] + f(i+1,j+1,m,triangle,dp);
        
        return dp[i][j] = min(dn, di);
    }
    

};