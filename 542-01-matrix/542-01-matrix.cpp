class Solution {
public:
    
    bool isValid(int x, int y, int m, int n)
    {
        if(x<0 || y<0 || x>=m || y>=n) return false;
        return true;
    }
    
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,-1}, {0,1}};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> dis(m, vector<int> (n,-1));
        
        queue<pair<int,int>> q;
        
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {   
                if(mat[i][j] == 0)
                {
                q.push({i,j});
                dis[i][j] = 0;
                }
            }
        }
        
        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();
            
            for(auto &c: dir )
            {
                int x = cur.first + c[0];
                int y = cur. second + c[1];
                if(isValid(x,y, m,n) && dis[x][y] == -1)
                {
                    q.push({x,y});
                    dis[x][y] = dis[cur.first][cur.second] + 1;
                }
            }
        }
        
        
        
        
        return dis;
        
        
    }
};