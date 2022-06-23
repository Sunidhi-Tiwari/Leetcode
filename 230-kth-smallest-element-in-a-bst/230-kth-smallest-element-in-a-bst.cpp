/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int ans;
    
    void solve(TreeNode* root, int k, int &ind)
    {
        if(!root) return;
        solve(root->left, k, ind);
          
        if(k == ind)
        {
            ans = root->val;
            ind++;
            return;
        }
        else ind++;
        solve(root->right, k, ind);
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
       int ind = 1;
       solve(root, k, ind);
           return ans;
        
    }
};