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
    int depth =  0;
    
    void compute_depth(TreeNode *node){                        // return the depth in O(d) time
        if(node->left != NULL){
            compute_depth(node->left);
            depth++;
        }
    }
    bool exists(int idx, int d, TreeNode *node){              // 
        int l = 0, r = pow(2, d)-1;
        int mid;
        for(int i =0; i < d; i++){
            mid = l+(r-l)/2;
            if(idx <= mid){
                node = node->left;
                r = mid;
            }else{
                node = node->right;
                l = mid+1;
            }
        }
        return node != NULL;
    }
    
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        compute_depth(root);
        if(depth == 0)
            return 1;
        
        int l = 1, r = pow(2, depth)-1;
        int mid;
        while(l <= r){
            mid = l + (r-l)/2;
            if(exists(mid, depth, root))
                l = mid+1;
            else
                r = mid-1;
        }
        cout << l;
        return (int)pow(2, depth)-1 + l;
    }
};
