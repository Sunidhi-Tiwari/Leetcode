class Solution {
public:
    
      bool isValid(int x, int y, int m, int n)
    {
        if(x<0 || y<0 || x>=m || y>=n) return false;
        return true;
    }
    
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,-1}, {0,1}};
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dis(m, vector<int> (n,-1));
        
         queue<pair<int,int>> q;
        int num = 0;
        
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {   
                if(grid[i][j] == 2)
                {
                q.push({i,j});
                dis[i][j] = 0;
                }
                
                if(grid[i][j] == 1 || grid[i][j] == 2)
                 num++;
            }
        }
        
        int ans = 0, cnt = 0;
        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();
            cnt++;
            
            for(auto &c: dir )
            {
                int x = cur.first + c[0];
                int y = cur. second + c[1];
                if(isValid(x,y, m,n) && dis[x][y] == -1 && grid[x][y] != 0)
                {
                    q.push({x,y});
                    dis[x][y] = dis[cur.first][cur.second] + 1;
                    ans = max(ans, dis[x][y]);
                }
            }
        }
        
       return (cnt == num) ? ans:-1;
        
        
    }
};