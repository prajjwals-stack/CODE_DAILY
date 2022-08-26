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
        if(root==NULL)return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        while(q.empty()==false){
            vector<int>v;
            int size=q.size();
            while(size--){
                TreeNode* curr=q.front();
                v.push_back(curr->val);
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};