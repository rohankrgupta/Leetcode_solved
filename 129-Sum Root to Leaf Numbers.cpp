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
    void helper(TreeNode *node, int &sum, int num){
    if(node == NULL)
        return;
     
    num = num*10 + node->val;
     
    if(node->left == NULL && node->right == NULL){
        sum+=num;
        return;
    }          
    
    if(node->left != NULL)
    helper(node->left, sum, num);
    if(node->right != NULL)
    helper(node->right, sum, num);
 }
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        helper(root, sum, 0);
        return sum;
    }
};
