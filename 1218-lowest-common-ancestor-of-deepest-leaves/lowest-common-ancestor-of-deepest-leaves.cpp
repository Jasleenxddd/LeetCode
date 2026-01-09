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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root) return nullptr;
        
        // map to store parent of each node
        unordered_map<TreeNode*, TreeNode*> mpp;
        queue<TreeNode*> q;
        q.push(root);

        // to keep curr bfs level, at x depth how which nodes are present
        // at the end it will have the deepest nodes
        vector<TreeNode*> lev;
        
        while(!q.empty()){
            int sz=q.size();
            lev.clear();

            for(int i=0; i<sz; i++){
                TreeNode* node=q.front();
                q.pop();
                lev.push_back(node);

                if(node->left){
                    mpp[node->left]=node;
                    q.push(node->left);
                }
                if(node->right){
                    mpp[node->right]=node;
                    q.push(node->right);
                }
            }
        }
        unordered_set<TreeNode*> st(lev.begin(), lev.end());
        while(st.size()>1){
            unordered_set<TreeNode*> nxt;
            for(auto it: st){
                nxt.insert(mpp[it]);
            }
            st=nxt;
        }
        return *st.begin();
    }
};