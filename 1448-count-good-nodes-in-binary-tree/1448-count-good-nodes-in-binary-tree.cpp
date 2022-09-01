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
    int total=0;
    void good(TreeNode* root,int max){
        if(root==NULL)return ;
        
        
        if(root->val>=max){
            total++;
            max=root->val;
           
            
        }
        good(root->left,max);
        good(root->right,max);
        
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int max=root->val;
        good(root,max);
        return total;
    }
};