class Solution {
    
    
 public:
    vector<int> ans;
    int target = 0;
    
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        
       vector<int> res(12,0);
       rec(11, numArrows, aliceArrows, 0, res);
       return ans;
       
    }
    
    void rec(int i, int count, vector<int>& aliceArrows, int sum,  vector<int> &res )
    {
        if(i < 0 || count<=0)
        {
            if(sum>target)
            {
                target = sum;
                 if (count > 0)
                {
                    res[0] += count;
                }
                ans = res;
            }
            
            return;
            
        }
        
        int req = aliceArrows[i] + 1;
        
        if(req<=count)
        {   
            res[i] = req;
            rec(i-1, count - req, aliceArrows, sum+i, res);
            res[i] = 0;
        }
        
        rec(i-1, count, aliceArrows, sum, res);
        return;
        
    }
};