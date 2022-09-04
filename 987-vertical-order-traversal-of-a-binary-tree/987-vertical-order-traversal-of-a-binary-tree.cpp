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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>Final_ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        map <int , map <int,vector<int>>> m;  
        q.push({root,{0,0}});
     
        
        while(q.empty()==false){
            
            int size=q.size();
            while(size--){
                TreeNode* curr=q.front().first;
                int x=q.front().second.first;
                int y=q.front().second.second;
                q.pop();
                
                m[x][y].push_back(curr->val);
                
                if(curr->left)q.push({curr->left,{x-1,y+1}});
                if(curr->right)q.push({curr->right,{x+1,y+1}});
                
            }
        }
        
        for(auto i:m){
        vector<int>ans;
        for(auto j:i.second){
            sort(j.second.begin(), j.second.end());
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
        Final_ans.push_back(ans);
    }
        return Final_ans;
    }
};