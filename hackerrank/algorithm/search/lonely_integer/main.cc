#include <iostream>
using namespace std;

int main(){
  int N;
  cin>>N;
  int A[100] = {0};
  int occur[100] = {0};
  
  for(int i=0;i<N;i++) cin>>A[i];

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(A[i] == A[j]) occur[i]++;
    }
  }

  for(int i=0;i<N;i++){
    if(occur[i] == 1) cout<<A[i]<<endl;
  }
  return 0;
}
