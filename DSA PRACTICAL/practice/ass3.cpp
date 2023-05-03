#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;
template<class T>
class node
  {
    public:
    T data;
    node<T> *next;
    };
template<class T>
class stack {
      node<T> * Top;
      T x;
      public:
      stack(){
      Top=NULL;
      }
      T empty();
      void push( T x);
      T pop();
      T getTop();
};
template<class T>
T stack<T>::empty(){
      if(Top==NULL){
        return 1;
      }
      else{
      return 0;
      }
}
template<class T>
void stack<T>::push(T x){
    node<T> * temp;
    temp=new node<T>;
    temp->data=x;
    temp->next=Top;
    Top=temp;
}
template<class T>
T stack<T>::pop(){
if(!empty()){
    node<T> *temp;
    temp=new node<T>;
    temp=Top;
    Top=Top->next;
    x=temp->data;
    delete temp;
    return x;
    }
    else{
    cout<<"Stack Is empty "<<endl;
    return 0;
    }
}
template<class T>
T stack<T>::getTop(){
    if(!empty()){
    node<T>* temp;
    temp =new node<T>;
    temp=Top;
    x=temp->data;
    return x;
    }
    else{
    cout<<"Stack is Empty"<<endl;
    return 0;
    }
}

class expression{
   public:
  
  char infix[30],postfix[30];
  void inputInfix();
  int precedence( char x);
  void infixToPostfix(char infix[],char postfix[]);
  int evaluate(char x,int op1,int op2);
  void evaPostfix(char postfix[]);
};

void expression::inputInfix(){
  cout<<"Enter Infix Expression :";
  cin>>infix;
  cout<<"Entered Infix Expression is :"<<infix;
  }
 
  int expression::precedence(char x){
    if(x=='(')
    return 0;
    if(x=='+' || x=='-')
    return 1;
    if(x=='*'||x=='/'=='%')
    return 2;
    return 3;
}

void expression::infixToPostfix(char infix[],char postfix[]){
   stack <char> s;
    char x,token;
    int i,j;
    j=0;
    for(i=0;infix[i]!='\0';i++){
      token=infix[i];
      if(isalnum(token)){
        postfix[j++]=token;
        }
      else if(token=='('){
        s.push('(');
        }
      else if(token==')'){
        while((x=s.pop())!='('){
          postfix[j++]=x;
        }
      }
      else{
      x=s.getTop();
      while(precedence(token)<precedence(x) && !s.empty()){
      x=s.pop();
      postfix[j++]=x;
      }
      s.push(token);
      }
}
while(!s.empty()){
  x=s.pop();
  postfix[j++]=x;
  }
  postfix[j++]='\0';
  cout<<postfix;
}
int expression::evaluate(char x,int op1,int op2){
  if(x=='+')
  return (op1+op2);
  if(x=='-')
  return (op1-op2);
  if(x=='*')
  return(op1*op2);
  if(x=='/')
  return (op1/op2);
  return x;
}
void expression::evaPostfix(char postfix[]){
   stack <int> s;
   char x;
   int op1,op2,val,i;
   for(i=0;postfix[i]!='\0';i++){
    x=postfix[i];
    if(isalpha(x)){
      cout<<"\n Enter the value of "<<x<<":";
      cin>>val;
      s.push(val);
      }
      else{
        op2=s.pop();
        op1=s.pop();
        val=evaluate(x,op1,op2);
        s.push(val);
        }
      }
val=s.pop();
cout<<"\n Value of expression is "<<val;
}

int main(){
  expression obj;
  int choice;
  do{
  cout<<endl<<endl;
  cout<<"MAIN MENU"<<endl;
  cout<<"\n 1]Take Infix Expression as input "<<endl;
  cout<<"\n 2]Conversion of Infix Expression To Postfix Expression "<<endl;
  cout<<"\n 3]Evaluate Postfix Expression "<<endl;
  cout<<"\n 4]Exit "<<endl;
  cout<<"Enter your Choice :";
  cin>>choice;
  switch(choice){
  case 1:obj.inputInfix();
  break;
  case 2:obj.infixToPostfix(obj.infix,obj.postfix);
  cout<<endl;
  cout<<"\n Postfix Expression is :"<<obj.postfix<<endl;
  break;
  case 3:obj.evaPostfix(obj.postfix);
  break;
  case 4:cout<<"Exit"<<endl;
  break;
  default :cout<<"Enter Valid Input "<<endl;
  }
  }while(choice!=3);
  return 0;
  }
  
