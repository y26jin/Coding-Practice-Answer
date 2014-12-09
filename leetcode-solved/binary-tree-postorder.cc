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
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> output;
    if(!root) return output;
        
    TreeNode *temp = root, *last = 0;
    deque<TreeNode*> cur;
    while(!cur.empty() || temp){
      if(temp){
	cur.push_front(temp);
	temp = temp->left;
      }
      else{
	TreeNode *head = cur.front();
	if(head->right && head->right != last) temp = head->right;
	else{
	  output.push_back(head->val);
	  last = head;
	  cur.pop_front();
	}
      }
    }
    return output;
  }
};
