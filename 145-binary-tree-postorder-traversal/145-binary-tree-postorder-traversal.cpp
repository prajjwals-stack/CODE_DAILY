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
    
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL)return {};
        
        stack<TreeNode*>s;
        stack<TreeNode*>s1;
        vector<int>ans;
        s.push(root);
        while( s.empty()==false){
            TreeNode* curr=s.top();
            s.pop();
            
            s1.push(curr);
             if(curr->left!=NULL){
                s.push(curr->left);
            }
            if(curr->right!=NULL){
                s.push(curr->right);
            }
           
            
            
        
        }
        while(s1.empty()==false){
            ans.push_back(s1.top()->val);
            s1.pop();
        }
        return ans;
    }
};