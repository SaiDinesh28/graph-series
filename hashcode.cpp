#include<bits/stdc++.h>
using namespace std;
bool isOperand(char ch){
  if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^' || ch=='(' || ch==')') return false;
  return true;
}
int outStackPrecedence(char ch){
  if(ch=='+' || ch=='-') return 1;
  if(ch=='*' || ch=='/') return 3;
  if(ch=='^') return 6;
  if(ch=='(') return 7;
  return 0;
}
int inStackPrecedence(char ch){
  if(ch=='+' || ch=='-') return 2;
  if(ch=='*' || ch=='/') return 4;
  if(ch=='^') return 5;
  return 0;
}
string infixToPostfix(string s){
  stack<char>st;
  int i=0;
  string ans="";
  while(i<s.size()){
    if(isOperand(s[i])) ans+=s[i++];
    else if(st.empty() || outStackPrecedence(s[i])>inStackPrecedence(st.top())) {if(s[i]!=')') st.push(s[i]); i++;}
    else {
     if(!st.empty() && outStackPrecedence(s[i])<=inStackPrecedence(st.top())) {
       if(st.top()!='(') ans+=st.top();
      else i++;
      st.pop();
     }
    }
  }
  while(!st.empty()) {
    ans+=st.top();st.pop();
  }
return ans;
}
int main(){
  string s;
  cin>>s;
  cout<<infixToPostfix(s)<<endl;

}