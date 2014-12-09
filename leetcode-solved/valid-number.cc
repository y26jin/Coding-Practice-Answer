class Solution {
public:
  bool isNumber(const char *s) {
    if(strlen(s) == 0) return false;
        
    int isNegative = -1, isFraction = -1, isNumAfterPoint = 0, isSci = -1, isNumeric = -1, isSpaceInNumber = 0, isExpo = 0;
    for(int i=0;i<strlen(s);i++){
      switch(s[i]){
      case ' ':
	if(isFraction == 1 || isNegative != -1 || isNumeric == 1) isSpaceInNumber = 1;
	break;
      case '+':
	if((isNegative != -1 && isSci != 1) || (isFraction == 1 && isSci != 1) || (isSci != 1 && isNumeric == 1) || isExpo) return false;
	else isNegative = 0;
	break;
      case '-':
	if((isNegative != -1 && isSci != 1) || (isFraction == 1 && isSci != 1) || (isSci != 1 && isNumeric == 1) || isExpo) return false;
	else isNegative = 1;
	break;
      case '.':
	if(isSpaceInNumber == 1) return false;
	if(isSci == 1) return false;
	if(isFraction == -1) isFraction = 1;
	else return false;
	break;
      case 'e':
	if(isSpaceInNumber == 1) return false;
	if(isSci == -1 && isNumeric == 1) isSci = 1;
	else return false;
	break;
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
	if(isNumeric == -1) isNumeric = 1;
	if(isSpaceInNumber == 1) return false;
	if(isSci == 1 && isExpo == 0) isExpo = 1;
	break;  
      default:
	return false;
      }
    }
        
    if(isNumeric == -1) isNumeric = 0;
    if(isSci == 1 && isExpo == 0) isNumeric = 0;
        
    return isNumeric;
  }
};
