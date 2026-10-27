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
    // void inOrder(TreeNode* root, vector<int>& res){
    //     if(root==nullptr){
    //         return;
    //     }
    //     inOrder(root->left, res);
    //     res.push_back(root->val);
    //     inOrder(root->right, res);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        
        // inOrder(root, res);

        // iterative
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* tmp=root;
        while(!st.empty() || tmp){
            while(tmp){
                st.push(tmp);
                tmp=tmp->left;
            }
            tmp=st.top();
            st.pop();
            ans.push_back(tmp->val);
            tmp=tmp->right;
        }
        return ans;


        //morris

        // vector<int> res;
        // TreeNode* curr=root;
        // while(curr!=nullptr){
        //     if(curr->left==nullptr){
        //         res.push_back(curr->val);
        //         curr=curr->right;
        //     }
        //     else{
        //         TreeNode* prev= curr->left;
        //         while(prev->right!=nullptr && prev->right!=curr){
        //             prev=prev->right;
        //         }
        //         if(prev->right==nullptr){
        //             prev->right=curr;
        //             curr=curr->left;
        //         }
        //         else{
        //             prev->right=nullptr;
        //             res.push_back(curr->val);
        //             curr=curr->right;
        //         }
        //     }
        // }
        // return res;
    }
};