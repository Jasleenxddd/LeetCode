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
    void inorder(TreeNode* root, int k, int& cnt, int& res){
        if(!root) return;
        inorder(root->left,k,cnt,res);
        cnt++;
        if(cnt==k){
            res=root->val;
            return;
        }
        inorder(root->right,k,cnt,res);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        int res;
        inorder(root, k, cnt, res);
        return res;
    }
};