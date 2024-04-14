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
    bool isLeaf(TreeNode* node){
        return (!node->left && !node->right);
    }
    int ret;
    void dfs(TreeNode* node){
        if(!node) return;
        if(node->left && isLeaf(node->left)){
            ret += node->left->val;
        }
        dfs(node->left);
        dfs(node->right);
    }
    int sumOfLeftLeaves(TreeNode* node) {
        ret = 0;
        dfs(node);
        return ret;
    }
};
