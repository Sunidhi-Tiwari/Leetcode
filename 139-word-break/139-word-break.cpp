class Solution {
public:
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
          queue<int> q({0});
        unordered_set<int> vstd;
        set<string> dict;
        for(auto a: wordDict) dict.insert(a);
        int n = s.size();
        while(!q.empty()) {
            int start = q.front();
            q.pop();
            if(vstd.count(start)) continue;
            vstd.insert(start);
            string sub;
            for(int i=start;i<n;i++) 
                if(dict.count(sub+=s[i])) {
                    q.push(i+1);
                    if(i+1 == n) return 1;    
                }
        }
        return 0;    
        
        
    }
};