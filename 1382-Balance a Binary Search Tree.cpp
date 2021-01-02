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
    
private:
    vector<int>pre;
    void preorder(TreeNode* root){
        if(root != NULL){
            preorder(root->left);
            pre.push_back(root->val);
            preorder(root->right);
        }
    }
    
    TreeNode* construct_tree(int l, int h){
        if(l > h)
            return NULL;
        
        int mid = l + (h-l)/2;
        TreeNode* root = new TreeNode(pre[mid]);
        root->left = construct_tree(l, mid-1);
        root->right = construct_tree(mid+1, h);
        return root;
    }
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        preorder(root);
        TreeNode *broot = construct_tree(0, pre.size()-1);
        return broot;
    }
};
