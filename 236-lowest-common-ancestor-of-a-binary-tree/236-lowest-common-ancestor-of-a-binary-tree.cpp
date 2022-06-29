/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* A, TreeNode* B, TreeNode* C) {
        
         if(A == NULL || A == B || A == C)
    return A;
    
    TreeNode* left = lowestCommonAncestor(A->left, B, C);
    TreeNode* right = lowestCommonAncestor(A->right, B, C);
    
    if(left == NULL) return right;
    else if(right == NULL) return left;
    else return A;
        
    }
};