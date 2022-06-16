class Solution {
public:
    
    struct node
    {
        int val;
        int row;
        int col;
        
        node(int v, int r, int c): val(v) , row(r), col(c)
        {
            
        }
        
    };
    
    struct comp
    {
        bool operator() (const node& a, const node& b)
        {
            return a.val>b.val;
        }
    };
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        
        priority_queue<node, vector<node>, comp> pq;
        int n = nums.size();
        int high = -1e9;
        
        for(int i = 0; i<n; i++)
        {
            pq.push(node(nums[i][0], i, 0));
            high = max(high, nums[i][0]);
        }
        
        int low = pq.top().val;
        
        vector<int> ans;
        ans = {low, high};
        
        while(pq.size() == n)
        {
            auto cur = pq.top();
            pq.pop();
            
            if(cur.col + 1 < nums[cur.row].size())
            {
                pq.push(node(nums[cur.row][cur.col + 1], cur.row, cur.col+1));
                
                high = max(high, nums[cur.row][cur.col+1]);
                
                low = pq.top().val;
                
                if(high - low < ans[1] - ans[0])
                {
                    ans[1] = high;
                    ans[0] = low;
                }
            }  
            
        }
        
        
        return ans;
    }
};