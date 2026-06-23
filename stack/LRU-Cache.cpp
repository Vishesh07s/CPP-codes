class Node
{
public:
  int key;
  int val;
  Node *next;
  Node *prev;
  Node(int k, int v)
  {
    key = k;
    val = v;
    next = prev = nullptr;
  }
};
class LRUCache
{
public:
  unordered_map<int, Node *> mpp;
  int capacity;
  Node *head;
  Node *tail;
  LRUCache(int capacity_)
  {
    capacity = capacity_;
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
  }

  void deleteNode(Node *node)
  {

    if (node->prev)
      node->prev->next = node->next;
    if (node->next)
      node->next->prev = node->prev;
  }

  void addAfterHead(Node *node)
  {
    node->next = head->next;
    node->next->prev = node;
    node->prev = head;
    head->next = node;
  }

  int get(int key)
  {
    if (mpp.find(key) != mpp.end())
    {
      Node *node = mpp[key];
      deleteNode(node);
      addAfterHead(node);
      return node->val;
    }
    else
      return -1;
  }

  void put(int key, int value)
  {
    if (mpp.find(key) != mpp.end())
    {
      Node *node = mpp[key];
      node->val = value;
      deleteNode(node);
      addAfterHead(node);
    }
    else
    {
      if (mpp.size() == capacity)
      {
        Node *node = tail->prev;
        mpp.erase(node->key);
        deleteNode(node);
        delete node;
      }
      Node *node = new Node(key, value);
      mpp[key] = node;
      addAfterHead(node);
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */