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
    vector<int>ans;
    void helper(TreeNode* root, int len){
        if(root==NULL)return ;
        if(ans.size()==len){
            ans.push_back(root->val);
        }
        
        helper(root->right,len+1);
        helper(root->left,len+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)return {};
        
        helper(root,0);
        return ans;
        // queue<TreeNode*>q;
        // q.push(root);
        // vector<int>ans;
        // while(q.empty()==false){
        //     int len=q.size();
        //     vector<int>v;
        //     while(len--){
        //         TreeNode* curr=q.front();
        //         q.pop();
        //         v.push_back(curr->val);
        //         if(curr->left)q.push(curr->left);
        //         if(curr->right)q.push(curr->right);
        //     }
        //     ans.push_back(v[v.size()-1]);
        // }
        // return ans;
    }
};