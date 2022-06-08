class Solution {
public:
    int lastStoneWeightII(vector<int>& A) {
        
        
         unordered_set<int> s1 = { 0 };
  for (auto i : A) {
    unordered_set<int> s2;
    for (auto j : s1) 
        s2.insert({ j - i, j + i });
    swap(s1, s2);
  }
  return abs(*min_element(begin(s1), end(s1), [](int i, int j) { return abs(i) < abs(j); }));
    }
};