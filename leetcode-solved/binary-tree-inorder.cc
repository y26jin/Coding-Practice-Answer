class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> out;
    if(!root) return out;
        
    deque<TreeNode*> cur,next;

    TreeNode *temp = root;
    while(!cur.empty() || temp){
      if(temp){
	cur.push_front(temp);
	temp = temp->left;
      }
      else{
	temp = cur.front();
	cur.pop_front();
	out.push_back(temp->val);
	temp = temp->right;
      }
    }
    return out;
  }
};
