class Solution {
public:
    void rotate(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i<n; i++)
        {
            for(int j = i; j<m; j++)
            {
                swap(grid[i][j], grid[j][i]);
            }
        }
        
        int k = m/2;
        
        for(int k = 0; k<m/2; k++)
        {
            for(int i = 0; i<n; i++)
                swap(grid[i][k], grid[i][m-1-k]);
        }
        
        return;
    }
};