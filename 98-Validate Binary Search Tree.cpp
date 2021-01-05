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
    vector<int>st;
    
    void inorder(TreeNode *node){
        if(node != NULL){
            inorder(node->left);
            st.push_back(node->val);
            inorder(node->right);
        }
    }
    
public:
    bool isValidBST(TreeNode* root) {
        inorder(root);
        for(int i = 0; i < st.size()-1; i++){
            if(st[i] >= st[i+1]){
                return false;
            }
        }
        return true;
    }
};
