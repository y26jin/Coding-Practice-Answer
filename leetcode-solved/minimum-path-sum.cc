class Solution {
public:
  int min(int a, int b){
    if(a>b) return b;
    if(a<=b) return a;
  }
  int minPathSum(vector<vector<int> > &grid) {
    if(grid.empty()) return 0;
        
    int m = grid.size(), n = grid[0].size();
    int val[1000][1000] = {0};
        
    val[0][0] = grid[0][0];
    for(int i=1;i<m;i++) val[i][0] = val[i-1][0] + grid[i][0];
    for(int i=1;i<n;i++) val[0][i] = val[0][i-1] + grid[0][i];
        
    for(int i=1;i<m;i++){
      for(int j=1;j<n;j++){
	val[i][j] = min(val[i-1][j], val[i][j-1]) + grid[i][j];
      }
    }
    return val[m-1][n-1];
  }
};
