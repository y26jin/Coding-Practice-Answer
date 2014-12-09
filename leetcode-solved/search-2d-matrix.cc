class Solution {
public:
  bool searchMatrix(vector<vector<int> > &matrix, int target) {
    if(matrix.empty()) return false;
        
    int m = matrix.size(), n = matrix[0].size();
    if(target < matrix[0][0] || target > matrix[m-1][n-1]) return false;
        
    int i = 0;
    while(i+1 <= m-1){
      if(matrix[i][0] <= target && target < matrix[i+1][0]) break;
            
      i++;
    }
    for(int j=0;j<n;j++){
      if(matrix[i][j] == target) return true;
    }
    return false;
  }
};
