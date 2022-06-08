class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        
        queue<int> q;
        
        int cnt = 0;
        
        for(auto edge: prerequisites)
        {
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }
        
        for(int i = 0; i<numCourses; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            cnt++;
            
            for(auto node: adj[cur])
            {
                indegree[node]--;
                if(indegree[node] == 0)
                    q.push(node);
                
            }
        }
        
        return cnt == numCourses;
        
    }
};