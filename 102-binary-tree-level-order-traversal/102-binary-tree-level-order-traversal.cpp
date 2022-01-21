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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        
        
        queue<TreeNode*>Q;
        Q.push(root);
        vector<vector<int>>v;
        while(Q.empty()==false){
            int len=Q.size();
            vector<int>level;
            
            while(len--){
            TreeNode *node=Q.front();
            Q.pop();
            level.push_back(node->val);
            if(node->left!=NULL)Q.push(node->left);
            if(node->right!=NULL)Q.push(node->right);
            }
            v.push_back(level);
        }
        return v;
    }
};