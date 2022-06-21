class Solution {
public:
     struct Node{
        vector<int> from; //parent(s), at most one node has 2 parents in a graph
        vector<int> to; //children, can have many children
    };
    unordered_map<int,Node> getNode;
    unordered_map<int,unordered_map<int,int>> edgeOrder;
    
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        //construct the graph, and record the node which has 2 parents if possible
        int N = edges.size();
        for(int n=1; n<=N; ++n)
            getNode[n] = Node();
        int node2parents = -1;
        for(int i=0; i<N; ++i){
            int p = edges[i][0];
            int c = edges[i][1];
            edgeOrder[p][c] = i;
            getNode[p].to.push_back(c);
            getNode[c].from.push_back(p);
            if(getNode[c].from.size()==2) //we find a node with 2 parents
                node2parents = c;
        }
        
        //doing DFS to find the loop if loop exists
        vector<int> status(N+1,0); // status 0,1,2 ==> 0:unvisited, 1:visiting, 2:visited
        stack<int> loop;
        bool loopfound = false;
        for(int i=1; i<=N; ++i){
            if(loopfound)   break;
            if(status[i] == 0){ //DFS started with node i
                status[i] = 1;
                stack<int> stk({i});
                DFS(stk,status,loopfound,loop);
                status[i] = 2;
            }
        }
        
        if(!loopfound){ // Case 1
            int parent1 = getNode[node2parents].from[0];
            int parent2 = getNode[node2parents].from[1];
            return (edgeOrder[parent1][node2parents] > edgeOrder[parent2][node2parents]) ?
                    vector<int>({parent1,node2parents}) : vector<int>({parent2,node2parents});
        }
        
        int last_occur_order = 0;
        vector<int> last_occur_edge;
        int begin = loop.top();
        while(!loop.empty()){
            int child = loop.top();
            loop.pop();
            int parent = loop.top();
            if(node2parents != -1 && child == node2parents) // Case 2
                return vector<int>({parent,child});
            int order = edgeOrder[parent][child];
            if(order > last_occur_order){
                last_occur_order = order;
                last_occur_edge = vector<int>({parent,child});
            }
            if(parent == begin)
                break; //loop ends
        }
        
        return last_occur_edge; // Case 3
    }
    
    void DFS(stack<int>& stk, vector<int>& status, bool& flag, stack<int>& loop){
        for(int c : getNode[stk.top()].to){
            if(flag)   return;
            if(status[c] == 1){
                stk.push(c);
                loop = stk;
                flag = true;
                return;
            }
            else if(status[c] == 0){
                stk.push(c);
                status[c] = 1;
                DFS(stk,status,flag,loop);
                status[c] = 2;
                stk.pop();
            }
        }
    }
    
    
};