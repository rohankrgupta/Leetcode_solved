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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int n = preorder.size();
        
        if(n == 0)
            return NULL;
        vector<int>lchild,rchild;
            
        for(int i = 1; i <n; i++){
            if(preorder[0] > preorder[i]){
                lchild.push_back(preorder[i]);
            }else{
                rchild.push_back(preorder[i]);
            }
        }
        TreeNode* root = new TreeNode(preorder[0]);
        root->left = bstFromPreorder(lchild);
        root->right = bstFromPreorder(rchild);
        
        return root;
    }
};
// Requires an O(n) time 

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
    TreeNode *helper(const vector<int>pre, int &id, int lim){
        if(id == pre.size() || pre[id] > lim)
            return NULL;
        TreeNode *root = new TreeNode (pre[id]);
        id++;
        root->left = helper(pre, id, root->val);
        root->right = helper(pre, id, lim);
        
        return root;

    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder){
        int id = 0;
        return helper(preorder, id, INT_MAX);
        
    }
};

