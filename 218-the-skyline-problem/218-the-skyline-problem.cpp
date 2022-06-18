class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    
        vector<vector<int>> ans; 
        
       // priority_queue<int> pq;
        multiset<int> mt;
        
        vector<pair<int, int>> plot;
        
        for(int i = 0; i<buildings.size(); i++)
        {
            int sp = buildings[i][0];
            int ep = buildings[i][1];
            int h = buildings[i][2];
            
            plot.push_back({sp, -h});
            plot.push_back({ep,h});
            
            
        }
        
        sort(plot.begin(), plot.end());
        
        mt.insert(0);
        int maxh = 0;
        
        for(auto a: plot)
        {
            
            if(a.second<0)
            {
                mt.insert(-a.second);
            }
            else
            {
                mt.erase(mt.find(a.second));
            }
            
            int curmax = *mt.rbegin();
            if(curmax != maxh)
            {
                ans.push_back({a.first, curmax});
                maxh = curmax;
            }
        }
        
        
        return ans;
        
    }
};