#include <iostream>
using namespace std;

class T_Node
{
	public:
		char sym;
		T_Node *left;
		T_Node *right;
		T_Node(char c){
        	        sym=c;
     	             }
};

class S_Node
{
	public:
    	int No;
    	T_Node*address;
    	S_Node*next;
};		

class Stack
{
	public:
		S_Node *top;
		Stack(){
			top = NULL;
		}
	void Push(T_Node*root);
    	T_Node*Pop();
    	T_Node*Get_Top();
        int Empty(); 
};

void Stack :: Push(T_Node*root)
  {
	S_Node*temp;
	temp = new S_Node;
   	temp->address = root;
   	
	if(top == NULL)
	{
		temp->next = NULL;
                top = temp;	
	}
	else
	{
		temp->next = top;
                top = temp;
	}	
}		
		
T_Node*Stack :: Pop()
{		
	T_Node *A;		
	if(top == NULL)
	{
    	return 0;
	}	
	else	
	{
		A = top->address;
		top = top->next;
		return (A);
	}	
}			
T_Node*Stack :: Get_Top()
{
	T_Node *A;	
    if (top != NULL)
    {
        A = top->address;
        return (A);
    }
    return NULL;
}	
int Stack :: Empty()
{
    if (top == NULL)
        return (1);
    else
        return (0);
}
class Exp_Tree
{
	string postfix;
	T_Node *root;
	Stack S;
			
	public:
		void Create_Postfix();
		int Priority(char op);
		void Inorder_Recursive(T_Node*root);
		void Preorder_Recursive(T_Node*root);
		void Postorder_Recursive(T_Node*root);	
};	
int Exp_Tree :: Priority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    else
        return 0;
}			
void Exp_Tree :: Create_Postfix()
{
    // postfix = " ";
	cout<<"\n========================================================================\n";
	cout<<"\n >> Enter the Postfix Expression :: ";
    cin>>postfix;
    
    for(int i=0;i<postfix.length();i++)
    {
        root = new T_Node(postfix[i]);
        root->left = NULL;
        root->right = NULL;
        
        if ((postfix[i] <= 'z' && postfix[i] >= 'a') || (postfix[i] <= 'Z' && postfix[i] >= 'A'))
        {
            S.Push(root);
        }
        
        else
        {
            if(Priority(postfix[i]))
            {
                root->right = S.Pop();
                root->left = S.Pop();
                S.Push(root);
            }
        }
    }
    root = S.Pop();
    cout<<"\n >>> Recursive Traversal Of Expression Tree :- \n"<<endl;
    cout<<" 1]  Inorder Traversal   ::  ";
    Inorder_Recursive(root);
    cout<<endl;
    cout<<" 2]  Preorder Traversal  ::  ";
    Preorder_Recursive(root);
    cout<<endl;
    cout<<" 3]  Postorder Traversal ::  ";
    Postorder_Recursive(root);
    cout<<endl;	cout<<"\n======================================================================="<<endl;
}
void Exp_Tree :: Inorder_Recursive(T_Node*root)
{
    if(root != NULL)
    {
    	Inorder_Recursive(root->left);
    	cout<<root->sym;
    	Inorder_Recursive(root->right);
    }
}
void Exp_Tree :: Preorder_Recursive(T_Node*root)
{
    if(root!= NULL)
    {
        cout<<root->sym;
        Preorder_Recursive(root->left);
        Preorder_Recursive(root->right);
    }
}
void Exp_Tree :: Postorder_Recursive(T_Node*root)
{
    if(root!= NULL){
        Postorder_Recursive(root->left);
        Postorder_Recursive(root->right);
        cout<<root->sym;
    }
}
int main()
{
    int choice;
    Exp_Tree obj;
    cout<<"\n \t\t\t =============================== \n";
	cout<<" \t\t\t ||   BINARY TREE TRAVERSAL   || \n";
	cout<<" \t\t\t =============================== \n\n";
 	do{	cout<<"\n======================================================================\n";
        cout<<" >>> Tree Traversal Menu :- \n\n 1] Create Tree From Postfix Expression \t 2] Exit Program  \n\n >> Enter your choice :: ";
        cin>>choice;
		cout<<"\n======================================================================\n";
        switch(choice) {
            case 1:
                obj.Create_Postfix(); 
                break;
            case 2:
               cout<<"\n \t -----> Program Exited Successfully --> "<<endl;
               break;
               default :cout<<"Enter Valid Input"<<endl;   
        }
    }while(choice!=2);
    return 0;
}
