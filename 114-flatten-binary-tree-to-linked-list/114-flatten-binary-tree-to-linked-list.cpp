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
   
        
       TreeNode* solve(TreeNode *root)
    {
        if(root == NULL)
        {
            return NULL;
        }
        
        TreeNode* left = solve(root->left);
        TreeNode * right = solve(root->right);
        root->right = left;
        root->left = NULL;
        
        TreeNode *ptr = root;
        while(ptr->right)
        {
            ptr = ptr->right;
        }
        ptr->right = right;
        return root;
    }
    
    void flatten(TreeNode* root) 
    {
        solve(root);
    }
};