class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> out;
    if(!root) return out;
        
    deque<TreeNode*> cur,next;
    cur.push_front(root);
    while(!cur.empty()){
      TreeNode *t = cur.front();
      cur.pop_front();
      out.push_back(t->val);
      if(t->right) cur.push_front(t->right);
      if(t->left) cur.push_front(t->left);
    }
    return out;
  }
};
