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
        
        cc--;
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        cc = n;
        
        par.resize(n);
        dep.assign(n,1);
        
        for(int i = 0; i<n; i++)
            par[i] = i;
        
        for(int i = 0; i<n; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                if(isConnected[i][j] && findpar(i) != findpar(j))
                    unite(i,j);
            }
        }
        
        dep.clear();
        par.clear();
        
        return cc;
        
    }
};