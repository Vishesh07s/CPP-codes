/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> parent;
    void fillMap(TreeNode * root){
        if(root == NULL) return;
        if(root -> left){
            parent[root -> left] = root;
            fillMap(root -> left);
        }
        if(root -> right){
            parent[root -> right] = root;
            fillMap(root -> right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        fillMap(root);
        queue<TreeNode *> q;
        q.push(target);
        unordered_set<int> visited;
        visited.insert(target -> val);

        while(!q.empty() ){
            if(k == 0) break;
            int size = q.size();
            for(int i = 0; i  <size; i++){
                TreeNode * curr = q.front();
                q.pop();
                if(curr -> left && !visited.count(curr -> left -> val)){
                    q.push(curr -> left);
                    visited.insert(curr -> left -> val);
                }
                    if(curr -> right && !visited.count(curr -> right -> val)){
                    q.push(curr -> right);
                    visited.insert(curr -> right -> val);
                }
                if(parent.count(curr) && !visited.count(parent[curr] -> val)){
                    q.push(parent[curr]);
                    visited.insert(parent[curr] -> val);
                }
            }
            k--;
        }
        while(!q.empty()){
            TreeNode * curr = q.front();
            q.pop();
            ans.push_back(curr -> val);
        }
        return ans;
    }
};