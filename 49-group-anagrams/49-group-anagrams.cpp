class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& A) {
        
         vector<vector<string> > sol;
    unordered_map<string, vector<string> > myMap;
    string temp;
    for(int i = 0; i < A.size(); i++){
        temp = A[i];
        sort(temp.begin(),temp.end());
        myMap[temp].push_back(A[i]);
    }
    
    auto it = myMap.begin();
    
    while(it != myMap.end()){
        sol.push_back(it->second);
        it++;
    }

    return sol;
        
        
        
    }
};