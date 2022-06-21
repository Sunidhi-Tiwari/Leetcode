class Solution {
public:
    
    
    vector<int> par;
    vector<int> dep;
    
    int cc;
    
       int findpar(int node)
    {
        if(par[node] == node)
            return node;
        
        return par[node] = findpar(par[node]);
    }
        
    void unite(int u, int v)
    {
         u = findpar(u);
         v = findpar(v);
        
        if(dep[u]>dep[v])
            par[v] = u;
        if(dep[v]>dep[u])
            par[u] = v;
        else
        {
            par[v] = u;
            dep[u]++;
        }
        
       
        return;
    }
        
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        par.resize(n+1);
        dep.assign(n+1, 0);
        cc = n;
        
        vector<int> ans;
        
        for(int i = 1; i<=n; i++)
            par[i] = i;
        
        for(int i = 0; i<n; i++)
        {
            
           
            
            if(findpar(edges[i][0]) != findpar(edges[i][1]))
            {
            unite(edges[i][0] , edges[i][1]);
            }
            else
            {
                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
                
                
                break;
            }
             
             
            
        }
        
            return ans;
    }
};