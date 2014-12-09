class Solution {
public:
  vector<int> getRow(int rowIndex) {
    int table[100][100];

    for(int i=0;i<100;i++){
      for(int j=0;j<=i;j++){
	if(j==0 || j==i) table[i][j] = 1;
	else table[i][j] = table[i-1][j-1] + table[i-1][j];
      }
    }
        
    vector<int> output;
    if(rowIndex < 0) return output;
        
    for(int i=0;i<=rowIndex;i++){
      output.push_back(table[rowIndex][i]);
    }
    return output;
  }
};
