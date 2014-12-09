#include <iostream>
using namespace std;

int main(){
  int T=0;
  cin>>T;

  int cycle[60] = {0};
  int results[60] = {0};
  for(int i=0;i<T;i++){
    cin>>cycle[i];
  }
  
  for(int i=0;i<T;i++){
    int temp = 1;
    for(int j=0;j<cycle[i];j++){
      if(j%2 == 0) temp = 2*temp;
      if(j%2 == 1) temp = temp+1;
    }
    results[i] = temp;
  }
  for(int i=0;i<T;i++){
    cout<<results[i]<<endl;
  }

  return 0;
}
