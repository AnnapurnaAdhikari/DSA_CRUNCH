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
     int sum = 0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        if(!root->left && !root->right){
            if(0 == targetSum - root->val) return true;
            // else targetSum += root->val;
        }
        
        targetSum -= root->val;
        return hasPathSum(root->left, targetSum)|| hasPathSum(root->right, targetSum);
    }
};