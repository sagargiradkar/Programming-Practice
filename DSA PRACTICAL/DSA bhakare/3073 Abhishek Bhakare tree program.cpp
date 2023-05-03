#include <iostream>
using namespace std;
class T_node{
    public:char Symb;
    T_node*L;
    T_node*R;
    T_node(char c){
        Symb=c;
    }
};
class S_node{
    public:int no;
    T_node*Addrs;
    S_node*next;
};
class Stack{
    S_node*Top1;
    public:
    Stack(){
        Top1=NULL;
    }
    void push(T_node*);
    T_node*pop();
    int is_empty();
    T_node*top();
};
void Stack::push(T_node*root){
	S_node*temp;
	temp=new S_node;
   	temp->Addrs=root;
   if(Top1==NULL){
        temp->next=NULL;
        Top1=temp;
    }
    else{
        temp->next=Top1;
        Top1=temp;
    }
}
T_node*Stack::pop(){
    T_node *A;
    if(Top1==NULL){
        //cout<<"Stack Underflow";
    }
    else{
        A=Top1->Addrs;
        Top1=Top1->next;
        return (A);
    }
    return 0;
}
T_node*Stack::top(){
    T_node*A;
    if(Top1!=NULL){
        A=Top1->Addrs;
        return(A);
    }
    
}
 int Stack::is_empty(){
    if(Top1==NULL){
        return(1);
    }
    else{
        return(0);
    }
    return 0;
}
class Exprs{
    T_node *root;
    Stack s;
    string postfix,prefix;
    public:void create_tr_frm_postfix();
    void create_tr_frm_prefix();
    bool is_Operator(char c);
    void inorder_rec(T_node*root);
    void inorder_n_rec(T_node*root);
    void preorder_rec(T_node*root);
    void preorder_n_rec(T_node*root);
    void postorder_rec(T_node*root);
    void postorder_n_rec(T_node*root);
};
bool Exprs::is_Operator(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'||c=='%'){
		return true;
	}
	else{
		return false;
	}
}
void Exprs::create_tr_frm_postfix(){
    postfix="";
	cout<<"Enter the postfix Expression:";
    cin>>postfix;
    for(int i=0;i<postfix.length();i++){
        root=new T_node(postfix[i]);
        root->L=NULL;
        root->R=NULL;
        if((postfix[i] >= 'a' && postfix[i] <= 'z')||(postfix[i] >= 'A' && postfix[i] <= 'Z')){
            s.push(root);
        }
        else{
            if(is_Operator(postfix[i])){
                root->R=s.pop();
                root->L=s.pop();
                s.push(root);
            }
        }
    }
   root=s.pop(); cout<<"==============================RECURSIVE TRAVERSAL OF EXPRESSION TREE=================================== "<<endl;
    cout<<"Inorder Rec Traversal:";
    inorder_rec(root);
    cout<<endl;
    cout<<"Preorder Rec Traversal:";
    preorder_rec(root);
    cout<<endl;
    cout<<"Postorder Rec Traversal:";
    postorder_rec(root);
    cout<<endl;
    cout<<"=========================================================================================================="<<endl;
    cout<<"==============================NON RECURSIVE TRAVERSAL OF EXPRESSION TREE ================================="<<endl;
    cout<<"Inorder Non Rec Traversal:";
    inorder_n_rec(root);
    cout<<endl;
    cout<<"Preorder Non Rec Traversal:";
    preorder_n_rec(root);
    cout<<endl;
    cout<<"Postorder Non Rec Traversal:";
    postorder_n_rec(root);
    cout<<endl;
    cout<<"=========================================================================================================="<<endl;
}
void Exprs::create_tr_frm_prefix(){
    prefix="";
    cout<<"Enter the prefix Expression:";
    cin>>prefix;
    for(int i=prefix.length()-1;i>=0;i--){
        root=new T_node(prefix[i]);
        root->L=NULL;
        root->R=NULL;
        if((prefix[i] >= 'a' && prefix[i] <= 'z')||(prefix[i] >= 'A' && prefix[i] <= 'Z')){
            s.push(root);
        }
        else{
            if(is_Operator(prefix[i])){
                root->L=s.pop();
                root->R=s.pop();
                s.push(root);
            }
        }
    }
   root=s.pop(); cout<<"==============================RECURSIVE TRAVERSAL OF EXPRESSION TREE=================================== "<<endl;
    cout<<"Inorder Rec Traversal:";
    inorder_rec(root);
    cout<<endl;
    cout<<"Preorder Rec Traversal:";
    preorder_rec(root);
    cout<<endl;
    cout<<"Postorder Rec Traversal:";
    postorder_rec(root);
    cout<<endl;
    cout<<"=========================================================================================================="<<endl;
    cout<<"==============================NON RECURSIVE TRAVERSAL OF EXPRESSION TREE ================================="<<endl;
    cout<<"Inorder Non Rec Traversal:";
    inorder_n_rec(root);
    cout<<endl;
    cout<<"Preorder Non Rec Traversal:";
    preorder_n_rec(root);
    cout<<endl;
    cout<<"Postorder Non Rec Traversal:";
    postorder_n_rec(root);
    cout<<endl;
    cout<<"=========================================================================================================="<<endl;
}
void Exprs::inorder_rec(T_node*p){
    if(p!=NULL){
    	inorder_rec(p->L);
    	cout << p->Symb;
    	inorder_rec(p->R);
    }
}
void Exprs::preorder_rec(T_node*p){
    if(p!=NULL){
        cout<<p->Symb;
        preorder_rec(p->L);
        preorder_rec(p->R);
    }
}
void Exprs::postorder_rec(T_node*p){
    if(p!=NULL){
        postorder_rec(p->L);
        postorder_rec(p->R);
        cout<<p->Symb;
    }
}
void Exprs::inorder_n_rec(T_node*p){
    while(p!=NULL || s.is_empty()==false){
        while(p!=NULL){
            s.push(p);
            p=p->L;
        }
        p=s.pop();
        cout<<p->Symb;
        p=p->R;
    }
    return;
}
void Exprs::preorder_n_rec(T_node*p){
    if(p==NULL)
        return;
    s.push(p);
    while(s.is_empty()==false){
        p=s.top();
        cout<<p->Symb;
        p=s.pop();
        if(p->R){
            s.push(p->R);}
        if(p->L){
            s.push(p->L);}
            
    }
}
void Exprs::postorder_n_rec(T_node*p){
    if(p==NULL){
        return;
    }
    else{
    Stack S1,S2;
    S1.push(p);
    T_node*node;
    while(!S1.is_empty()){
        node=S1.pop();
        S2.push(node);
        if(node->L){
            S1.push(node->L);
        }
        if(node->R){
            S1.push(node->R);
        }
    }
    while(!S2.is_empty()){
        node=S2.pop();
        cout<<node->Symb;
    }
    }
}

int main(){
    int choice;
    Exprs obj;
    cout<<"<<<<<<<<<<<<<<<<<<<<<<<<TREE TRAVERSAL>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    while(true){
        cout<<"++++++++++++++++++++++++Menu++++++++++++++++++++\n1] Create tree from pstfix exp \n2] Create tree from prfix exp\n3] Exit  \nEnter your choice:";
        cin>>choice;
        switch(choice){
            case 1:
                obj.create_tr_frm_postfix(); 
                break;
            case 2:
                obj.create_tr_frm_prefix();
                break;
            case 3:
                cout<<"Exit Successfully";
                break;
            default:cout<<"Enter the valid choice:";
        }
        if(choice==3){
            break;
        }
    }
    return 0;
}
