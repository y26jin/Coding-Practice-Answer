#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>

using namespace std;

struct loc {
  char label;
  int x;
  int y;
  int num;
};

void mark_sink(int **m, deque<loc> &sink, int n){
  int count = 0;
  // corner
  if(m[0][1] > m[0][0] && m[1][0] > m[0][0] && m[1][1] > m[0][0]){
    loc temp;
    temp.label = count+'A';
    temp.x=0;
    temp.y=0;
    temp.num=0;
    sink.push_back(temp);
    count++;
  }
  if(m[n-2][0] > m[n-1][0] && m[n-1][1] > m[n-1][0] && m[n-2][1] > m[n-1][0]){
    loc temp;
    temp.label = count+'A';
    temp.x=n-1;
    temp.y=0;
    temp.num=0;
    sink.push_back(temp);
    count++;
  }
  if(m[0][n-2] > m[0][n-1] && m[1][n-1] > m[0][n-1] && m[1][n-2] > m[0][n-1]){
    loc temp;
    temp.label = count+'A';
    temp.x=0;
    temp.y=n-1;
    temp.num=0;
    sink.push_back(temp);
    count++;
  }
  if(m[n-2][n-2] > m[n-1][n-1] && m[n-1][n-2] > m[n-1][n-1] && m[n-2][n-1] > m[n-1][n-1]){
    loc temp;
    temp.label = count+'A';
    temp.x=n-1;
    temp.y=n-1;
    temp.num=0;
    sink.push_back(temp);
    count++;
  }
  
  // sides
  for(int i=1;i<=n-2;i++){
    int j=0;
    if(m[i-1][j]>m[i][j] && m[i+1][j]>m[i][j] && m[i-1][j+1]>m[i][j] && m[i][j+1]>m[i][j] && m[i+1][j+1]>m[i][j]){
      loc temp;
      temp.label = count+'A';
      temp.x=i;
      temp.y=j;
      temp.num=0;
      sink.push_back(temp);
      count++;
    }
  }
  for(int j=1;j<=n-2;j++){
    int i=n-1;
    if(m[i-1][j-1]>m[i][j] && m[i-1][j]>m[i][j] && m[i-1][j+1]>m[i][j] && m[i][j-1]>m[i][j] && m[i][j+1]>m[i][j]){
      loc temp;
      temp.label = count+'A';
      temp.x=i;
      temp.y=j;
      temp.num=0;
      sink.push_back(temp);
      count++;
    }
  }
  for(int i=1;i<=n-1;i++){
    if(m[i-1][n-1]>m[i][n-1] && m[i+1][n-1]>m[i][n-1] && m[i-1][n-2]>m[i][n-1] && m[i][n-2]>m[i][n-1] && m[i+1][n-2]>m[i][n-1]){
      loc temp;
      temp.label = count+'A';
      temp.x=i;
      temp.y=n-1;
      temp.num=0;
      sink.push_back(temp);
      count++;
    }
  }
  for(int i=1;i<=n-2;i++){
    if(m[0][i-1]>m[0][i] && m[0][i+1]>m[0][i] && m[1][i-1]>m[0][i] && m[1][i]>m[0][i] && m[1][i+1]>m[0][i]){
      loc temp;
      temp.label = count+'A';
      temp.x=0;
      temp.y=i;
      temp.num=0;
      sink.push_back(temp);
      count++;
    }
  }

  // centers
  for(int i=1;i<=n-2;i++){
    for(int j=1;j<=n-2;j++){
      if(m[i-1][j-1]>m[i][j] && m[i][j-1]>m[i][j] && m[i+1][j-1]>m[i][j] && m[i-1][j]>m[i][j] && m[i+1][j]>m[i][j] && m[i-1][j+1]>m[i][j] && m[i][j+1]>m[i][j] && m[i+1][j+1]>m[i][j]){
	loc temp;
	temp.label = count+'A';
	temp.x=i;
	temp.y=j;
	temp.num=0;
	sink.push_back(temp);
	count++;
      }
    }
  }

}

char find_sink(char **out, int i,int j,deque<loc> &sink){
  // if this pos is sink
  deque<loc>::iterator it;
  for(it=sink.begin();it!=sink.end();it++){
    if(*it->i == i && *it->j == j) return *it->label;
  }

  // check neighbours
  deque<loc> stream;
  // find the next move;
  while(find_next_move)
}

int main(){
  int n;
  cin>>n;
  int **mat = new int * [n];
  for(int i=0;i<n;i++){
    mat[i] = new int [n];
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>mat[i][j];
    }
  }

  deque<loc> sink;

  mark_sink(mat,sink,n);

  char **out = new char* [n];
  for(int i=0;i<n;i++){
    out[i] = new char [n];
  }  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++) out[i][j] = '-';
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      out[i][j] = find_sink(out,i,j,sink);
    }
  }
  
  deque<loc>::iterator it;
  for(it = sink.begin(); it != sink.end(); it++){
    cout<<*it->num<<" ";
  }
  cout<<endl;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<out[i][j]<<"";
    }
    cout<<endl;
  }
  return 0;
}
