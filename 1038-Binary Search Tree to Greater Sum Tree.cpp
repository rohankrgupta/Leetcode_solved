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
int sum;
private:
    void helper(TreeNode* root){
        if(root != NULL){
            sum+=root->val;
            helper(root->left);
            helper(root->right);
        }
    }
    void helper1(TreeNode* root, int &sum){
        if(root != NULL){
            helper1(root->left, sum);
            int tmp = root->val;
            root->val = sum;
            sum = sum-tmp;
            helper1(root->right, sum);
        }
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        sum = 0;
        helper(root);
        helper1(root, sum);
        return root;
    }
};

// O(n) time complexity
