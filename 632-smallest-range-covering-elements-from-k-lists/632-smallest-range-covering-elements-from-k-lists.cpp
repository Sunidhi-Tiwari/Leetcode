class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        int n = nums.size();
        vector<pair<int,int>> a;
        
        for(int i = 0; i<nums.size(); i++)
        {
            for(auto j: nums[i])
            {
                a.push_back({j,i});
            }
            
        }
        
        sort(a.begin(), a.end());
        
        int mini = 1e9;
        int diff = nums.size();
        int arr[diff];
        
        memset(arr, 0, sizeof(arr));
        
        int total = 0;
        int j = 0;
        
        vector<int> ans;
        
        for(int i = 0; i<(int)a.size(); i++)
        {
            arr[a[i].second]++;
            if(arr[a[i].second] == 1) total++;
            
            if(total == diff)
            {
                if(a[i].first - a[j].first + 1< mini)
                {
                    mini = a[i].first - a[j].first + 1;
                    ans = {a[j].first,a[i].first};
                }
            }
            
            if(total == diff)
            {
            while(total == diff)
            {
                if(arr[a[j].second]>1) arr[a[j].second]--, j++;
                else
                    break;
            }
            
            if(a[i].first - a[j].first + 1< mini)
                {
                    mini = a[i].first - a[j].first + 1;
                
                    ans = { a[j].first,a[i].first };
                }
            }
        }
        
        return ans;
    }
};