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
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1){
            TreeNode* temp = new TreeNode(v);
            temp->left = root;
            root = temp;
        }else{
            stack < pair <TreeNode*, int> > st;
            st.push({root, 2});
            int lvl = 0;
            pair <TreeNode*, int> temp;
            TreeNode* node;
            while(!st.empty()){
                temp = st.top();
                st.pop();
                lvl = temp.second;
                node = temp.first;
                if(lvl == d){
                    TreeNode* temp1 = new TreeNode(v);
                    TreeNode* temp2 = new TreeNode(v);
                    temp1->left = node->left;
                    temp2->right = node->right;
                    node->left = temp1;
                    node->right = temp2;
                }else{
                    if(node->left){
                        st.push({node->left, lvl + 1});
                    }
                    if(node->right){
                        st.push({node->right, lvl + 1});
                    }
                }
            }
        }
        return root;
    }
};
