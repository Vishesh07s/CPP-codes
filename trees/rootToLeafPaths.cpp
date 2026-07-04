/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  bool isLeaf(Node * node){
      if(node -> left == nullptr && node -> right == nullptr) return true;
      return false;
  }
    void getPath(Node * root, vector<int> path, vector<vector<int>> &ans){
        if(root == nullptr) return;
        path.push_back(root -> data);
        if(isLeaf(root)){
            ans.push_back(path);
            return;
        }
        getPath(root -> left, path, ans);
        getPath(root -> right, path, ans);
        
        
    }
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        getPath(root, {}, ans);
        return ans;
        
    }
};