class Solution {
public:
  int uniquePaths(int m, int n) {
    int val[400][400] = {1};
    for(int i=1;i<400;i++){
      for(int j=0;j<=i;j++){
	if(j==0 || j == i) val[i][j] = 1;
	else val[i][j] = val[i-1][j-1] + val[i-1][j];
      }
    }
    return val[m+n-2][n-1];
  }
};
