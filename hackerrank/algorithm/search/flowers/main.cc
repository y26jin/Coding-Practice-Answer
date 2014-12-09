/* Sample program illustrating input/output */
#include<iostream>
#include <cstdlib>

int cmp(const void *a, const void *b){
  return (*(int*)b- *(int*)a);
}


using namespace std;
int main(void){

 

  //Helpers for input and output

  int N, K;
  cin >> N >> K;
  int C[N];
  for(int i = 0; i < N; i++){
    cin >> C[i];
  }
   
  int result = 0;
  qsort(C,N,sizeof(int),cmp);

  int round;
  if(N <= K){
    // easy case
    for(int i=0;i<N;i++){
      result = result + C[i];
    }
    cout<<result<<endl;
  }
  else{
    // hard case
    int round = (N-N%K)/K;
    for(int i=0;i<round;i++){
      for(int j = i*K; j < (i+1)*K; j++) result = result + (i+1)*C[j];
    }
    for(int i=round*K;i<N;i++){
      result = result + (round+1)*C[i];
    }
    cout<<result<<endl;
  }
   
  return 0;
}
