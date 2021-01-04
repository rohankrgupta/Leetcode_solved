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
    int maxsum = INT_MIN;
    int max_gain(TreeNode *node){
        if(node == NULL)
            return 0;
        
        // max sum on the left and right of the subtrees
        int left_gain = max(max_gain(node->left), 0);
        int right_gain = max(max_gain(node->right), 0);
        
        // the price to start the new path where 'node' is the highest node
        int price_newpath = node->val + left_gain + right_gain;
        
        // Update the max_sum if its better to start the new path
        maxsum = max(maxsum, price_newpath);
        
        // for recursion:
        // return max_gain if continue the same path
        return node->val + max(left_gain, right_gain);
    }
public:
    int maxPathSum(TreeNode* root) {
      max_gain(root);
        return maxsum;
    }
};
