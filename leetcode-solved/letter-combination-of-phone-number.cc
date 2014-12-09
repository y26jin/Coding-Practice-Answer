class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> out;
    if(digits==""){
      out.push_back(digits);
      return out;
    }
        
    vector<string> temp;
    helper(digits, temp, 0, out);
    return out;
  }
    
  void helper(string d, vector<string> &t, int pos, vector<string> &out){
    if(t.size() == d.length()){
      string temp_s;
      for(int i=0;i<t.size();i++) temp_s += t[i];
      out.push_back(temp_s);
      return;
    }
        
    vector<string> md = mapping(d[pos]);
    if(md.empty()) helper(d,t,pos+1,out);
    else{
      for(int i=0;i<md.size();i++){
	t.push_back(md[i]);
	helper(d,t,pos+1,out);
	t.pop_back();
      }
    }
  }
    
  vector<string> mapping(char button){
    vector<string> out;
    switch(button){
    case '0':
      out.push_back(" ");
      break;
    case '1':
      break;
    case '2':
      out.push_back("a");
      out.push_back("b");
      out.push_back("c");
      break;
    case '3':
      out.push_back("d");
      out.push_back("e");
      out.push_back("f");
      break;
    case '4':
      out.push_back("g");
      out.push_back("h");
      out.push_back("i");
      break;
    case '5':
      out.push_back("j");
      out.push_back("k");
      out.push_back("l");
      break;
    case '6':
      out.push_back("m");
      out.push_back("n");
      out.push_back("o");
      break;
    case '7':
      out.push_back("p");
      out.push_back("q");
      out.push_back("r");
      out.push_back("s");
      break;
    case '8':
      out.push_back("t");
      out.push_back("u");
      out.push_back("v");
      break;
    case '9':
      out.push_back("w");
      out.push_back("x");
      out.push_back("y");
      out.push_back("z");
      break;
    }
        
    return out;
  }
};
