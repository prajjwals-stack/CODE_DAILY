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
    int sum=0;
    void path( TreeNode* root,string s){
        if(root==NULL)return;
        
        s=s+to_string(root->val);
        if(!root->left && !root->right){
            sum+=stoi(s);
        }
        path(root->left,s);
        path(root->right,s);
    }
    
    int sumNumbers(TreeNode* root) {
        string s="";
        path(root,s);
        return sum;
    }
};