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
    TreeNode* bst(vector<int>& preorder, int& i, int ub){
        if(i==preorder.size() || preorder[i]>ub) return nullptr;
        TreeNode* root=new TreeNode(preorder[i]);
        i++;
        root->left=bst(preorder, i, root->val);
        root->right=bst(preorder, i, ub);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return bst(preorder, i, INT_MAX);
    }
};