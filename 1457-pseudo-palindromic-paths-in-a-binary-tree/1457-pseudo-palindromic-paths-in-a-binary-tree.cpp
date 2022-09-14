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
    map<int,int>m;
    int cnt=0;
    void helper(TreeNode* root){
        if(root==NULL)return;
        int odd=0;
        m[root->val]++;
        helper(root->left);
        helper(root->right);
        if(!root->left && !root->right)
        {
            for(int i=0;i<10;i++){
            if(m[i]%2!=0){
                odd++;
            }
        }
        if(odd<=1){
            cnt++;
        }
        }
        
        m[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root==NULL)return 0;
        
        helper(root);
        return cnt;
        
    }
};