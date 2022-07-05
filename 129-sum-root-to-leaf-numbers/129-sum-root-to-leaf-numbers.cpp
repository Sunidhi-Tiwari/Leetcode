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
    
    int ans = 0;
    
    
    void roottosum(TreeNode* root, int sum)
    {
        
        if(!root) return;
        sum = sum*10 + root->val;
        
        if(!root->left && !root->right)
        { 
         ans = ans + sum;
         return;
        }
        
        roottosum(root->left, sum);
        roottosum(root->right, sum);
        
        return;
        
    }
    int sumNumbers(TreeNode* root) {
        
        
        if(root == NULL) return 0;
        
        int sum = 0;
        
        roottosum(root, sum);
        return ans;
        
        
        
        
    }
};