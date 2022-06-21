class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
         vector<bool> ans;
       vector<vector<int>> isReachable(n, vector<int> (n, 0));
       queue<int> q;
	   //adjacency list
        vector<vector<int>> adj(n);
        for(auto &p : prerequisites){
            adj[p[0]].push_back(p[1]);
        }   
		//visited 
        vector<vector<int>> visited(n, vector<int>(n, 0));
        
        for(int i=0; i<n; i++){
            q.push(i);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                 for(int neighbor : adj[node]){
                    if(visited[i][neighbor]) continue;       
                    isReachable[i][neighbor]  = 1;
                    visited[i][neighbor] = 1;          
                    q.push(neighbor);
                }
            }
        }
        
        for(auto &q : queries){
            ans.push_back(isReachable[q[0]][q[1]]);
        }      
        return ans;
        
    }
};