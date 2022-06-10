class Solution {
public:
    bool searchMatrix(vector<vector<int>>& grid, int x) {
        
         int n = grid.size();
    int m = grid[0].size();
    
    if(grid[0][0] > x || grid[n-1][m-1] < x)
    {
        
        return false;
    }
    int i = 0; int j = m - 1;
    while( i<n && j>=0)
    {
        if(grid[i][j] == x)
        {
           
            return true;
        }
        
        if(grid[i][j] > x) j--;
        else i++;
            
    }
    
    return false;
        
    }
};