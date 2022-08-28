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
    vector<string>ans;
    void  path(TreeNode* root,string v){
        if(root==NULL )return ;
        
        v=v+"->"+to_string(root->val);
        if(root->left==NULL && root->right==NULL)ans.push_back(v);
        path(root->left,v);
        path(root->right,v);
    
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL)return {};
        string s=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            return {to_string(root->val)};
        }
        if(root->left)path(root->left,s);
        if(root->right)path(root->right,s);
        return ans;
    }
};