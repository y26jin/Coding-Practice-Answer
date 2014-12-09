class Solution {
public:
  void helper(vector<vector<int>> &out, vector<int> &line, int n, vector<int> &num, int visit[]){
    if(line.size() == n){
      out.push_back(line);
      return;
    }
    for(int i=0;i<n;i++){
      if(visit[i] == 0) {
	line.push_back(num[i]);
	visit[i] = 1;
	helper(out,line,n,num,visit);
	line.pop_back();
	visit[i] = 0;
      }
    }
  }
  vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int>> output;
    if(num.empty()) return output;
        
    vector<int> line;
    int *visit = new int [num.size()];
    for(int i=0;i<num.size();i++) visit[i] = 0;
    helper(output,line,num.size(),num,visit);
    return output;
  }
};
