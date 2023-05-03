#include<iostream>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode *left;
    TreeNode *right;
   
    TreeNode(){
     left=NULL;
    right=NULL;
    }
    };
class BST{
    public:
    TreeNode *root;
    BST(){
    root=NULL;
    }
    TreeNode* create();
    TreeNode* insert(TreeNode* root,int x);
    TreeNode* search(int key);
     TreeNode* getMin(TreeNode *root);
    TreeNode* deleten(TreeNode*root,int key);
    void inorder(TreeNode *root);
    void preorder(TreeNode *root);
    void postorder(TreeNode *root);
    };
TreeNode* BST::create(){
  int n,i,key;
  cout<<"\nEnter the number of Nodes :";
  cin>>n;
  for(i=0;i<n;i++){
  cout<<"\nEnter the data :";
  cin>>key;
  
  root=insert(root,key);
  }
  return root;
}
TreeNode*  BST::insert(TreeNode* root,int x){
  if(root==NULL){
      root=new TreeNode;
      root->data=x;
      root->left=NULL;
      root->right=NULL;
      return root;
      }
    if(x>root->data){
      root->right=insert(root->right,x);
      return root;
      }
    if(x<root->data){
    root->left=insert(root->left,x);
    return root;
      }
return root;
}
void BST::inorder(TreeNode*root){
  if(root!=NULL){
      inorder(root->left);
      cout<<root->data<<" ";
      inorder(root->right);
      }
}
void BST::postorder(TreeNode*root){
  if(root !=NULL){
      postorder(root->left);
      postorder(root->right);
      cout<<root->data<<" ";
  }
}
void BST::preorder(TreeNode*root){
  if(root!=NULL){
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
  }
}
 TreeNode* BST::search(int key)
    {
        TreeNode *temp=root;
        while(temp!=NULL)
        {
            if(temp->data==key)
                return root;
            else if(temp->data<key)
                temp=temp->right;
            else
                temp=temp->left;
        }
        return NULL;
    }
TreeNode*BST::getMin(TreeNode* root){
      while(root->left!=NULL){
      root=root->left;
      }
      return root;
    }
TreeNode* BST::deleten(TreeNode*root,int key){
   TreeNode *temp;
   if(root==NULL){
   return NULL;
   }
   if(key<root->data){
    root->left=deleten(root->left,key);
     return root;
     }
     if(key>root->data){
      root->right=deleten(root->right,key);
      return root;
      }
      
      //element found 
      //no chiled
      if(root->left ==NULL& root->right==NULL){
        temp=root;
        delete temp;
        return NULL;
        }
        // one child
        if(root->left!=NULL && root->right==NULL){
          temp=root;
          root=root->left;
          delete temp;
          return root;
          }
          if(root->left==NULL && root->right!=NULL){
          temp=root;
          root=root->right;
          delete temp;
          return root;
          }
          //both Child present 
          temp=getMin(root->right);
          root->data=temp->data;
          root->right=deleten(root->right,temp->data);
          return root;
   }
 
int main(){
    BST obj;
    int choice;
    do{
        cout<<"\nMain Menu "<<endl;
        cout<<"1]Create a tree"<<endl;
        cout<<"2]Display Binary Tree "<<endl;
        cout<<"3]Search Element "<<endl;
        cout<<"4]Delete Element "<<endl;
        cout<<"5]Traversals Menu "<<endl;
        cout<<"6]Exit From Program "<<endl;
        cout<<"Enter your Choice  :"<<endl;
        cin>>choice;
        switch(choice){
        case 1:obj.root=obj.create();
        break;
        case  2:
        cout<<"\n----------------------------------------------------";
        cout<<"\nBINARY TREE :-";
        obj.inorder(obj.root);
        cout<<"\n----------------------------------------------------";
        break;
        case  3: 
        int key;
        TreeNode*result;
                 cout<<"\n-------------------------------";
            cout<<"\nEnter the Node to search :";
            cin>>key;
            result = obj.search(key);
            if(result==NULL)
            {
                cout<<"\nNODE "<<key<<" NOT FOUND";
            }
            else
            {
                cout<<"\nNODE "<<key<<" IS FOUND";
            }
            cout<<"\n---------------------------------";
                  break;
        case 4: cout<<"\n----------------------------------";
            cout<<"\nEnter the Node to delete :";
            cin>>key;
            result = obj.deleten(obj.root,key);
          obj.root=result;
            cout<<"\nNODE DELETED !!";
            cout<<"\n-----------------------------------";
        break;
        case 5:int ch;
                    do{
                    cout<<"\nMain Menu For Traversal "<<endl;
                    cout<<"1] Inorder Traversal "<<endl;
                    cout<<"2] Preorder Traversal"<<endl;
                    cout<<"3] Postorder Traversal "<<endl;
                    cout<<"4]Exit From Traversal Menu "<<endl;
                    cout<<"Enter Choice :"<<endl;
                    cin>>ch;
                    switch(ch){
                    case 1:
                    cout<<"\n----------------------------------------------------";
                    cout<<"\nBINARY TREE :-";
                    obj.inorder(obj.root);
                    cout<<"\n----------------------------------------------------";
                    break;
                    case  2:
                    cout<<"\n----------------------------------------------------";
                    cout<<"\nBINARY TREE :-";
                    obj.preorder(obj.root);
                    cout<<"\n----------------------------------------------------";
                    break;
                    case 3:
                    cout<<"\n----------------------------------------------------";
                    cout<<"\nBINARY TREE :-";
                    obj.postorder(obj.root);
                    cout<<"\n----------------------------------------------------";
                    break;
                    case 4:cout<<"Exit From Traversal Menu "<<endl;
                    break;
                    default :
                    cout<<"Enter Valid  Input !!!"<<endl;
                    }
                    }while(ch!=4);
        break;
        case 6:cout<<"Exit From Program "<<endl;
        break;
        default:
        cout<<"Enter valid input  "<<endl;
        }
        }while(choice!=6);
        
        return 0;
        }
