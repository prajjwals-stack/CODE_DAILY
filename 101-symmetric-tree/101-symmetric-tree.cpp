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
    bool symetric(TreeNode* p,TreeNode* q){
        if(p==NULL || q==NULL){
            if(p==q)return true;
            else return false;
        }
        if(p->val!=q->val)return false;
        return  symetric(p->left,q->right) && symetric(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        
        return symetric(root->left,root->right);
    }
};