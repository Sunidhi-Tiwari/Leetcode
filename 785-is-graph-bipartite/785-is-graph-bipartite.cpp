class Solution {
public:
    
    vector<bool> vis;
    vector<int> col;
    
    
    bool dfs(int node, int c, vector<vector<int>>& graph)
    {
        vis[node] = true;
        col[node] = c;
        
        for(auto a : graph[node])
        {   
            if(!vis[a])
            {
            if(!dfs(a,c^1, graph))
                return false;
            }
            
            if(col[a] == col[node])
                return false;
        }
        
        return true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vis.assign(n, false);
        col.resize(n);
        
        for(int i = 0; i<n; i++)
        {
            if(!vis[i])
            {
                if(!dfs(i,0, graph))
                    return false;
            }
        }
        
        return true;
    }
};