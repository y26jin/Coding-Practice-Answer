/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int> > output;
    if(!root) return output;
        
    queue<TreeNode*> cur,next;
    cur.push(root);
    vector<int> head;
    head.push_back(root->val);
    output.push_back(head);
    while(!cur.empty()){
      TreeNode *t = cur.front();
      cur.pop();
      if(t){
	next.push(t->left);
	next.push(t->right);
      }
      if(cur.empty()){
	cur = next;
	vector<int> temp;
	while(!next.empty()){
	  TreeNode *r = next.front();
	  next.pop();
	  if(r) temp.push_back(r->val);
	}
	if(!temp.empty()) output.push_back(temp);
      }
    }
    return output;
  }
};
