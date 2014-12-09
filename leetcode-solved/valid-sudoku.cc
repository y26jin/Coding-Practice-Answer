class Solution {
public:
  bool isValid(vector<vector<char>> &board){
    // check row
    for(int i=0;i<9;i++){
      int a[10]={0};
      for(int j=0;j<9;j++) if(board[i][j] >= '0' && board[i][j] <= '9') a[board[i][j]-'0']++;
      for(int j=0;j<10;j++) if(a[j] > 1) return false;
    }
    // check col
    for(int i=0;i<9;i++){
      int a[10] = {0};
      for(int j=0;j<9;j++) if(board[j][i] >= '0' && board[j][i] <= '9') a[board[j][i]-'0']++;
      for(int j=0;j<10;j++) if(a[j] > 1) return false;
    }
    // check cells
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
	int x[10] = {0};
	for(int a=3*i;a<3*i+3;a++){
	  for(int b=3*j;b<3*j+3;b++){
	    if(board[a][b] >= '0' && board[a][b] <= '9') x[board[a][b]-'0']++;
	  }
	}
	for(int k=0;k<10;k++) if(x[k] > 1) return false;
      }
    }
    return true;
  }
  bool isValidSudoku(vector<vector<char> > &board) {
    if(board.empty()) return false;
    if(board.size() != 9) return false;
        
    return isValid(board);
  }
};
