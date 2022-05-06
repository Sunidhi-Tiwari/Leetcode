class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    
       int m = obstacleGrid.size();
       int n = obstacleGrid[0].size();
       
       if( obstacleGrid[m-1][n-1] == 1)
           return 0;
           
       vector<vector<int>> dp(m, vector<int>(n,-1));
        
        
        
       return f(m-1,n-1,obstacleGrid, dp);
        
    }
    
    int f(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp)
    {
        if(i == 0 && j == 0)
           return dp[i][j] = 1;
        if(i<0 || j<0) return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int up = 0;
        int left = 0;
        
        if(i>0)
        {
             if(obstacleGrid[i-1][j] != 1)
             {
                 up = f(i-1,j,obstacleGrid,dp);
             }
       
       
        }
            
        if(j>0)
        {
              if(obstacleGrid[i][j-1] != 1)
              {
                  left = f(i,j-1,obstacleGrid,dp);
              }
        }
        
        return dp[i][j] = up + left;
    }
};