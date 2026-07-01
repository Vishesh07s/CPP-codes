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

// phele left boundary travel kro
// fir leaves tarvel kro
// fir right boundary travel kro

class Solution
{
public:
  bool isLeaf(Node *node)
  {
    if (node->left == nullptr && node->right == nullptr)
      return true;
    return false;
  }
  void addLeftBoundary(Node *root, vector<int> &res)
  {
    Node *curr = root->left;
    while (curr)
    {
      if (!isLeaf(curr))
      {
        res.push_back(curr->data);
      }
      if (curr->left)
        curr = curr->left;
      else
        curr = curr->right;
    }
  }

  void addRightBoundary(Node *root, vector<int> &res)
  {
    Node *curr = root->right;
    stack<int> st;
    while (curr)
    {
      if (!isLeaf(curr))
        st.push(curr->data);
      if (curr->right)
        curr = curr->right;
      else
        curr = curr->left;
    }
    while (!st.empty())
    {
      res.push_back(st.top());
      st.pop();
    }
  }

  void addLeaves(Node *root, vector<int> &res)
  {
    if (root == nullptr)
      return;
    if (isLeaf(root))
    {
      res.push_back(root->data);
      return;
    }
    addLeaves(root->left, res);
    addLeaves(root->right, res);
  }

  vector<int> boundaryTraversal(Node *root)
  {
    vector<int> res;
    if (!root)
      return res;
    if (!isLeaf(root))
      res.push_back(root->data);
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
  }
};