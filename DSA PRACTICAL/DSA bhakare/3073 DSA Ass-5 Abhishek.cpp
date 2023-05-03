#include<iostream>
using namespace std;
class TreeNode {
  public:
    int value;
  TreeNode * left;
  TreeNode * right;

  TreeNode() {
    value = 0;
    left = NULL;
    right = NULL;
  }
};
class BST {
    public:
    TreeNode * root;
  BST() {
    root = NULL;
  }
  void insertNode(TreeNode *root);
  void printPreorder(TreeNode *root);
  void printInorder(TreeNode *root);
  void printPostorder(TreeNode *root);
  TreeNode *recursiveSearch(TreeNode *root , int val);
  TreeNode * minValueNode(TreeNode *root );
  TreeNode * minValueNode1(TreeNode *root); 
  int height(TreeNode *root);
  TreeNode* Mirror_BST(TreeNode*root);
  TreeNode* copy(TreeNode*root);
  TreeNode*deleteNode(TreeNode *root, int val);
};
void BST :: insertNode(TreeNode * new_node) {
    if (root == NULL) {
      root = new_node;
      cout << "Value Inserted as root node!" << endl;
    } else {
      TreeNode * temp = root;
      while (temp != NULL) {
        if (new_node -> value == temp -> value) {
          cout << "Value Already exist,please Insert another value!" << endl;
          return;
        } else if ((new_node -> value < temp -> value) && (temp -> left == NULL)) {
          temp -> left = new_node;
          cout << "Value is less than Corresponding root node , Inserted to the left!" << endl;
          break;
        } else if (new_node -> value < temp -> value) {
          temp = temp -> left;
        } else if ((new_node -> value > temp -> value) && (temp -> right == NULL)) {
          temp -> right = new_node;
          cout << "Value is greater than Corresponding root node ,  Inserted to the right!" << endl;
          break;
        } else {
          temp = temp -> right;
        }
      }
    }
}
void BST :: printPreorder(TreeNode * r){
    if (r == NULL)
        return;
    cout << r -> value << " ";
    printPreorder(r -> left);
    printPreorder(r -> right);
}
void BST :: printInorder(TreeNode * r){
    if (r == NULL)
      return;
    printInorder(r -> left);
    cout << r -> value << " ";
    printInorder(r -> right);
}
void BST:: printPostorder(TreeNode * r){
    if (r == NULL)
        return;
    printPostorder(r -> left);
    printPostorder(r -> right);
    cout << r -> value << " ";
  }

TreeNode * BST::recursiveSearch(TreeNode * r, int val) {
    if (r == NULL || r -> value == val)
      return r;

    else if (val < r -> value)
      return recursiveSearch(r -> left, val);

    else
      return recursiveSearch(r -> right, val);
}
int BST ::height(TreeNode * r) {
    if (r == NULL)
      return -1;
    else {
      return (1+max(height(r->left),height(r->right)));
    }
}
TreeNode *BST:: minValueNode(TreeNode * node) {
    TreeNode * current = node;
    /* loop down to find the leftmost leaf */
    while (current -> left != NULL) {
      current = current -> left;
    }
    return current;
}
TreeNode *BST:: minValueNode1(TreeNode * node) {
    TreeNode * current = node;
    /* loop down to find the leftmost leaf */
    while (current -> left != NULL) {
      current = current -> left;
    }
    cout<< current->value<<endl;
    return NULL;
}
TreeNode*BST:: Mirror_BST(TreeNode*p){
   	    TreeNode*temp=p;
       if(p!=NULL){
       	  	temp=p->right;
           p->right=p->left;
           p->left=temp;
           Mirror_BST(p->left);
           Mirror_BST(p->right);
           cout<<"Tree  is Copied"<<endl;
       }
       return NULL;
}
TreeNode*BST::copy(TreeNode*p){
    TreeNode*Copy=p;
    Copy=NULL;
    if(p!=NULL){
        Copy->value=p->value;
        Copy->left=copy(p->left);//copy left subtree
        Copy->right=copy(p->right);//copy right subtree
        cout<<"Tree is Swapped/mirrored"<<endl;
    }
    return(Copy);
}
TreeNode *BST:: deleteNode(TreeNode * r, int val) {
    if (r == NULL) {
      return NULL;
    }
    else if (val < r -> value) {
      r -> left = deleteNode(r -> left, val);
    }
    else if (val > r -> value) {
      r -> right = deleteNode(r -> right, val);
    }
    else {
      // node with only one child or no child 
      if (r -> left == NULL) {
        TreeNode * temp = r -> right;
        delete r;
        return temp;
      } 
      else if (r -> right == NULL) {
        TreeNode * temp = r -> left;
        delete r;
        return temp;
      } 
      else {
        TreeNode * temp = minValueNode(r -> right);
        r -> value = temp -> value;
        r -> right = deleteNode(r -> right, temp -> value);
      }
    }
    return r;
  }
int main() {
  BST obj;
  int choice, val;

  do {
    cout << "===============================BINARY SEARCH TREE===================================" << endl;
    cout << "1] Insert a Node in BST \n2] Search Node \n3] Delete Node \n4] Traverse of BST \n5] Height of Tree  \n6] Smallest value of Node in BST \n7] Display the Mirror image \n8] Copy tree \n9] Exit Program" << endl;
    cout<<"Enter operation to do: ";
    cin >> choice;
    TreeNode * new_node = new TreeNode();
    switch (choice) {
    case 1:
        cout <<"INSERT OPERATION"<<endl;
        cout <<"Enter VALUE to INSERT in BST: ";
	    cin >> val;
	    new_node->value = val;
	    obj.insertNode(new_node);
	    cout<<endl;
    	break;
    case 2:
        cout << "SEARCH OPERATION" << endl;
        cout << "Enter value of node to search in BST: ";
        cin >> val;
        new_node = obj.recursiveSearch(obj.root, val);
        if (new_node != NULL) {
            cout << "Value found" << endl;
        }
        else {
            cout << "Value not found" << endl;
        }
        break;
    case 3:
        cout << "DELETE OPERATION " << endl;
        cout << "Enter value of node to delete in BST: ";
        cin >> val;
        new_node = obj.recursiveSearch(obj.root,val);
        if (new_node != NULL) {
            obj.deleteNode(obj.root, val);
            cout << "Value Deleted" << endl;
        }
        else {
            cout << "Value not found" << endl;
        }
        break;
    case 4:
        cout <<"IN-ORDER TRAVERSAL: ";
        obj.printInorder(obj.root);
        cout<<endl;
        cout <<"PRE-ORDER TRAVERSAL: ";
        obj.printPreorder(obj.root);
      	cout<<endl;
        cout <<"POST-ORDER TRAVERSAL: ";
      	obj.printPostorder(obj.root);
      	cout<<endl;
        break;
    case 5:
        cout << "TREE HEIGHT" << endl;
        cout << "Height : " << obj.height(obj.root) << endl;
        break;
    case 6:
        cout<<"Smallest Node in BST:";
        obj.minValueNode1(obj.root);
        break;
    case 7:
        obj.Mirror_BST(obj.root);
        break;
    case 8:
        obj.copy(obj.root);
        break;
    case 9:
        break;
    default:
        cout << "Enter valid choice" << endl;
    }
  } while (choice != 9);
    return 0;
}


