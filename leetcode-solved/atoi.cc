class Solution {
public:
  int atoi(const char *str) {
    if(strlen(str) == 0) return 0;
        
    long long int n = 0;
    int sign = 0;
    int j=0, plus = 0, minus = 0, lastsign = 0xfffffff;
    while(str[j] == ' ' || str[j] == '+' || str[j] == '-'){
      if(str[j] == '+') {
	plus ++;
	lastsign = j;
      }
      if(str[j] == '-'){
	minus ++;
	lastsign = j;
      }
      if(str[j] == ' ' && lastsign < j && lastsign != 0xfffffff) return 0;
            
      j++;
    }
    if(plus>1 || minus>1 || (plus>0 && minus >0)) return 0;
    if(plus == 1 && minus == 0) sign = 0;
    else if(plus == 0 && minus == 1) sign = 1;
        
    for(int i=j;i<strlen(str);i++){
      int num = str[i] - '0';
      if(num >= 0 && num <= 9){
	n *= 10;
	n += num;
      }
      else break;
    }
       
    if(sign == 0){
      if(n > INT_MAX) return INT_MAX;
      else return n;
    }
    else if(sign == 1){
      if(0-n < INT_MIN) return INT_MIN;
      else return 0-n;
    }
        
  }
};
