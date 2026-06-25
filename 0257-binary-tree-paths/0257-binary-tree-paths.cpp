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
    vector<int> nodes;
    vector<string> paths;
    void dfs(TreeNode* root){
        if(!root)return;
        
        nodes.push_back(root->val);
        
        //leaf node
        if(!root->left && !root->right){
            string path = ""; 
            for(int  i =0; i < nodes.size(); i++){
                path += to_string(nodes[i]);
                if(i != nodes.size()-1) path += "->";
            } 
            paths.push_back(path);  
        }
        dfs(root->left);
        dfs(root->right);
        nodes.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);   

        return paths;
        
    }
};