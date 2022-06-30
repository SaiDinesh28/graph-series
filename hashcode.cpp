#include<bits/stdc++.h>
using namespace std;
bool isOperand(char ch){
  if(ch=='+' || ch=='-' || ch=='*' || ch=='/') return false;
  return true;
}
int precedence(char ch){
  if(ch=='+' || ch=='-') return 1;
  if(ch=='*' || ch=='/') return 2;
  return 0;
}
string infixToPostfix(string infix){
  int i=0;
  string postfix="";
  stack<char>st;
  while(i<infix.size()){
     if(isOperand(infix[i])) {
      postfix+=infix[i];
      i++;
     }
     else{
      if(st.empty() || precedence(infix[i])>precedence(st.top())) {
        st.push(infix[i]);i++;
      }
      else{
        postfix+=st.top();
        st.pop();
      }
     }
  }
  while(!st.empty()) {
    postfix+=st.top();
    st.pop();
  }
  return postfix;
}
int main(){
  string s;
  cin>>s;
  cout<<infixToPostfix(s)<<endl;

}