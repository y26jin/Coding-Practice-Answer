class Solution {
public:
  vector<vector<int> > generate(int numRows) {
    vector<vector<int>> output;
    if(numRows <= 0) return output;
        
    int table[100][100] = {0};
    for(int i=0;i<100;i++){
      for(int j=0;j<=i;j++){
	if(j==0 || j==i) table[i][j] = 1;
	else table[i][j] = table[i-1][j-1] + table[i-1][j];
      }
    }
        
    for(int i=0;i<numRows;i++){
      vector<int> line;
      for(int j=0;j<=i;j++){
	line.push_back(table[i][j]);
      }
      output.push_back(line);
    }
    return output;
  }
};
