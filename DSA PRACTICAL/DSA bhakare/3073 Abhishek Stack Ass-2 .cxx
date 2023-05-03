#include <iostream>
#include<math.h>//for exponentiation
#include<algorithm>
using namespace std;
template<class T> class Node{
    public:
     T Oper;
     Node<T>*next;
};
template<class T> class stack{
    Node<T>*Top;//SP
  public:
      stack(){
         Top= NULL;
      }
     int is_empty();
     void push(T c);
     T pop();
     T top();
};
template<class T>
int stack<T>::is_empty(){
    if(Top==NULL){
        return(1);
    }
    else{
        return(0);
    }
    return 0;
}
template<class T>
void stack<T>::push(T c){
    Node<T>*add;
    add=new Node<T>;
    add->Oper=c;
    add->next=Top;
    Top=add;
}
template<class T>
T stack<T>:: pop(){
    T c;
    if(!is_empty()){
        Node<T>*add;
        add=new Node<T>;
        add=Top;
        Top=Top->next;
        c=add->Oper;
        return c;
    }
    return 0;
}
template<class T>
T stack<T>::top(){
    if(!is_empty()){
        T c;
        Node<T>*add;
        add=new Node<T>;
        add=Top;
        c=add->Oper;
        return c;
    }
    return 0;
    
}
class Expression{
	private:string infix,postfix,prefix;//String Input taken 
	public:void Input();
	int priority(char c);
	bool is_Operator(char c);
	string Infix_To_Postfix();
	string Infix_To_Prefix();
	int Postfix_Evaluation();
	int Prefix_Evaluation();
};
void Expression::Input(){
	  	infix="",postfix="",prefix="";
	  	cout<<"Enter a Infix Expression :";
	  	cin>>infix;
}
bool Expression::is_Operator(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
	{
		return true;
	}
	else
	{
		return false;
	}
}
int Expression::priority(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 
string Expression::Infix_To_Postfix()
{
	//string postfix;
	stack<char> s;
	for(int i=0;i<infix.length();i++)
	{
		if((infix[i] >= 'a' && infix[i] <= 'z')
		||(infix[i] >= 'A' && infix[i] <= 'Z'))
		{
			postfix+=infix[i];
		}
		else if(infix[i] == '(')
		{
			s.push(infix[i]);
		}
		else if(infix[i] == ')')
		{
			while((s.top()!='(') && (!s.is_empty()))
			{
				char temp=s.top();
				postfix+=temp;
				s.pop();
			}
			if(s.top()=='(')
			{
				s.pop();
			}
		}
		else if(is_Operator(infix[i]))
		{
			if(s.is_empty())
			{
				s.push(infix[i]);
			}
			else{
				while((!s.is_empty())&&( priority(infix[i])<=priority(s.top())))	{
						postfix+=s.top();
						s.pop();
				}
				s.push(infix[i]);
			
			}
		}
	}
	while(!s.is_empty()){
		postfix+=s.top();
		s.pop();
	}
	return postfix;
}
string Expression::Infix_To_Prefix(){
    stack<char> s;
	reverse(infix.begin(),infix.end());//TO REVERSE THE INFIX EXPRESSION TO CONVERT IT INTO PREFIX EXPRESSION
	for(int i=0;i<infix.length();i++)
	{
		if((infix[i] >= 'a' && infix[i] <= 'z')
		||(infix[i] >= 'A' && infix[i] <= 'Z'))
		{
			prefix+=infix[i];
		}
		else if(infix[i] == ')')
		{
			s.push(infix[i]);
		}
		else if(infix[i] == '(')
		{
			while((s.top()!=')') && (!s.is_empty()))
			{
				char temp=s.top();
				prefix+=temp;
				s.pop();
			}
			if(s.top()==')')
			{
				s.pop();
			}
		}
		else if(is_Operator(infix[i]))
		{
			if(s.is_empty())
			{
				s.push(infix[i]);
			}
			else{
					while((!s.is_empty())&&( priority(infix[i])<=priority(s.top())))
					{
						prefix+=s.top();
						s.pop();
					}
					s.push(infix[i]);
				}
				
			}
		
	}
	while(!s.is_empty()){
		prefix+=s.top();
		s.pop();
	}
	reverse(prefix.begin(),prefix.end());
	return prefix;
}
	
int Expression::Postfix_Evaluation(){
	stack <int> sp;//object creation of integer stack
	for(int i=0;i<postfix.length();i++){
	    if((postfix[i] >= 'a' && postfix[i] <= 'z')||(postfix[i] >= 'A' && postfix[i] <= 'Z')){
	        cout<<"Enter the value of  "<<postfix[i]<<"=";
	        cin>>postfix[i];
	        if(postfix[i]>'0' && postfix[i]<'9'){
			    sp.push(postfix[i]-'0');
	        }
		}
		else{
			int op2=sp.top();
			sp.pop();
			int op1=sp.top();
			sp.pop();
			switch(postfix[i]){
				case '+':
				sp.push(op1+op2);//Addition operation
				break;
				case '-':
				sp.push(op1-op2);//Subtraction
				break;
				case '*':
				sp.push(op1*op2);//multiplication operation
				break;
				case '/':
				sp.push(op1/op2);//Dividation operation
				break;
				case '^':
				sp.push(pow(op1,op2));//Exponent operation Between two operands
				break;
			}
		}
	}
	postfix=" ";
	return sp.top();
}
int Expression::Prefix_Evaluation(){
	stack <int> sp;//object creation of integer stack
	for(int i=0;i<prefix.length();i++){
		if((prefix[i] >= 'a' && prefix[i] <= 'z')||(prefix[i] >= 'A' && prefix[i] <= 'Z')){
	        cout<<"Enter the value of"<<prefix[i]<<"=";
	        cin>>prefix[i];
	         if(prefix[i]>'0' && prefix[i]<'9'){
			    sp.push(prefix[i]-'0');
	         }
		}
		else{
			int op2=sp.top();
			sp.pop();
			int op1=sp.top();
			sp.pop();
			switch(prefix[i]){
				case '+':
				sp.push(op1+op2);//Addition operation
				break;
				case '-':
				sp.push(op1-op2);//Subtraction
				break;
				case '*':
				sp.push(op1*op2);//multiplication operation
				break;
				case '/':
				sp.push(op1/op2);//Dividation operation
				break;
				case '^':
				sp.push(pow(op1,op2));//Exponent operation Between two operands
				break;
			}
		}
	}
	prefix=" ";
	return sp.top();
}
int main() 
{  
	Expression p;//Object creation of expression class
	int choice;
	while(true){
	cout<<"***********Menu*************\n1] Infix To Postfix Expression \n2] Eval Postfix Expression  \n3] Infix To Prefix Expression \n4] Eval Prefix Expression \n5] Exit \nEnter your choice:";
	cin>>choice;
		switch(choice){
			case 1:
			p.Input();//input expression
			cout<<endl<<"POSTFIX EXPRESSION="<<p.Infix_To_Postfix()<<endl;
			break;
			case 2:
      			cout<<p.Postfix_Evaluation()<<endl;
      			break;
			case 3:
			    p.Input();//input expression
  			    cout<<"Prefix Expression="<<p.Infix_To_Prefix()<<endl;
				break;
  			case 4:
      			cout<<p.Prefix_Evaluation()<<endl;
  			case 5:
  				break;
  			default:cout<<"Enter the valid choice"<<endl;
		}
		if(choice==5){
					cout<<"Exit Successfully";
					break;
		}
	}	
	return 0;
}