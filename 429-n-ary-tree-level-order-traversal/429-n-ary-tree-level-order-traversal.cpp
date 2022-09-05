/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL)return {};
        queue<Node*>q;
        vector<vector<int>>ans;
        
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>v;
            while(size--){
                Node* curr=q.front();
                q.pop();
                v.push_back(curr->val);
                
                for(auto it: curr->children){
                    q.push(it);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};