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
    void help(TreeNode* root,vector<int>&v){
        if(root==NULL){
            return;
        }
        help(root->left,v);
        v.push_back(root->val);
        help(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>v;
        help(root,v);
        unordered_map<int,int>m;
        for(int i=0;i<v.size();i++){
            if(m.find(k-v[i])!=m.end()){
                return true;
            }
            m[v[i]]=i;
        }
        return false;
    }
};