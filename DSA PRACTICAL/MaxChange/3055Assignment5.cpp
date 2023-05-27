#include <iostream>
using namespace std;

class Tnode
{
public:
    int no;
    Tnode *left;
    Tnode *right;
};

class BST
{
private:
    Tnode *root;
    Tnode *s;
    int f = 0;

public:
    BST();
    void insert();
    void deleteNode(int num);
    void rpre_travers(Tnode *);
    void rpost_travers(Tnode *);
    void rin_travers(Tnode *);
    void successor(Tnode *, int n);
    bool search(int num);
    int depth(Tnode *);
    void Mirror_BST(Tnode *);
    void leaf(Tnode *);
    void controlBST();
    bool BST_check();
};

BST::BST()
{
    root = NULL;
};

bool BST::BST_check()
{
    if (root == NULL)
    {
        cout << "Tree is Empty" << endl;
        return false;
    }
    else
    {
        return true;
    }
};

void BST::insert()
{
    int num, choice, flag2 = 0;
    while (flag2 == 0)
    {
        cout << "\nEnter the element: ";
        cin >> num;
        if (root == NULL)
        {
            root = new Tnode;
            root->no = num;
            root->left = NULL;
            root->right = NULL;
        }
        else
        {
            int flag = 0;
            Tnode *temp;
            temp = root;
            while (flag == 0)
            {
                if (num == temp->no)
                {
                    cout << "\nElement in already present in tree" << endl;
                    break;
                }
                if (num > temp->no)
                {
                    if (temp->right == NULL)
                    {
                        temp->right = new Tnode;
                        temp = temp->right;
                        temp->no = num;
                        temp->left = temp->right = NULL;
                        flag = 1;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
                else if (num < temp->no)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = new Tnode;
                        temp = temp->left;
                        temp->no = num;
                        temp->left = temp->right = NULL;
                        flag = 1;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
            }
        }
        while (true)
        {
            cout << "Do you want to add next element?\n(1) Yes\n(2) No ---> ";
            cin >> choice;
            if (choice == 1)
            {
                break;
            }
            else if (choice == 2)
            {
                flag2 = 1;
                break;
            }
            else
            {
                cout << "\nEnter a valid choice" << endl;
            }
        }
    }
};

void BST::successor(Tnode *root, int n)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        successor(root->left, n);
        if (root->no == n)
        {
            f = 1;
        }
        if (f == 1 && root->no > n)
        {
            s = root;
            f = 0;
        }
        successor(root->right, n);
    }
};

void BST::rin_travers(Tnode *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        rin_travers(root->left);
        cout << root->no << " ";
        rin_travers(root->right);
    }
};

void BST::rpre_travers(Tnode *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        cout << root->no << " ";
        rpre_travers(root->left);
        rpre_travers(root->right);
    }
};

void BST::rpost_travers(Tnode *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        rpost_travers(root->left);
        rpost_travers(root->right);
        cout << root->no << " ";
    }
};

int BST::depth(Tnode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + max(depth(root->left), depth(root->right));
    }
};

void BST::deleteNode(int num)
{
    if (root != NULL)
    {
        Tnode *temp = root;
        Tnode *temp2 = root;
        int flag = 0;
        do
        {
            if (num == temp->no)
            {
                if (temp->left != NULL && temp->right != NULL)
                {
                    successor(temp, num);
                    Tnode *suc = temp;
                    temp2 = temp;
                    temp = temp->right;
                    int check = 0;
                    if (temp->no == s->no)
                    {
                        temp2->right = NULL;
                    }
                    else
                    {
                        while (temp != NULL && temp->no != s->no)
                        {
                            temp2 = temp;
                            if (temp->left != NULL)
                            {
                                temp = temp->left;
                                check = 1;
                            }
                            else
                            {
                                temp = temp->right;
                                check = 2;
                            }
                        }
                        if (check == 1)
                        {
                            temp2->left = NULL;
                        }
                        if (check == 2)
                        {
                            temp2->right = NULL;
                        }
                    }
                    suc->no = s->no;

                    temp = NULL;
                }
                else if (temp->left == NULL && temp->right == NULL)
                {
                    if (flag == 0)
                    {
                        root = NULL;
                    }
                    if (flag == 1)
                    {
                        temp2->left = NULL;
                    }
                    if (flag == 2)
                    {
                        temp2->right = NULL;
                    }
                    temp = NULL;
                }
                else if (temp->left != NULL && temp->right == NULL)
                {
                    if (flag == 0)
                    {
                        root = root->left;
                    }
                    if (flag == 1)
                    {
                        temp2->left = temp->left;
                    }
                    if (flag == 2)
                    {
                        temp2->right = temp->left;
                    }
                    temp = NULL;
                }
                else if (temp->left == NULL && temp->right != NULL)
                {
                    if (flag == 0)
                    {
                        root = root->right;
                    }
                    if (flag == 1)
                    {
                        temp2->left = temp->right;
                    }
                    if (flag == 2)
                    {
                        temp2->right = temp->right;
                    }
                    temp = NULL;
                }
            }
            else
            {
                if (num < temp->no)
                {
                    temp2 = temp;
                    temp = temp->left;
                    flag = 1;
                }
                else if (num > temp->no)
                {
                    temp2 = temp;
                    temp = temp->right;
                    flag = 2;
                }
            }
        } while (temp != NULL);
    }
};

bool BST::search(int num)
{
    if (root != NULL)
    {
        Tnode *temp = root;
        do
        {
            if (temp->no == num)
            {
                cout << "Element " << num << " found" << endl;
                break;
            }
            else
            {
                if (num < temp->no)
                {
                    temp = temp->left;
                }
                else if (num > temp->no)
                {
                    temp = temp->right;
                }
            }
        } while (temp != NULL);
        if (temp == NULL)
        {
            cout << "Element " << num << " not found" << endl;
            return false;
        }
    }
    return true;
};

void BST::Mirror_BST(Tnode *root)
{
    if (root != NULL)
    {
        Tnode *temp = root->right;
        root->right = root->left;
        root->left = temp;
        Mirror_BST(root->left);
        Mirror_BST(root->right);
    }
};

void BST::leaf(Tnode *root)
{
    if (root != NULL && root->left == NULL && root->right == NULL)
    {
        cout << root->no << " ";
    }
    if (root == NULL)
    {
        return;
    }
    else
    {
        leaf(root->left);
        leaf(root->right);
    }
};

void BST::controlBST()
{
    cout << "This is Demonstration of Binary Search Tree" << endl;
    cout << "\nLet's Create a BST:-" << endl;
    insert();
    int ak = 0, choice;
    while (ak == 0)
    {
        cout << "\nEnter your choice:\n(1) Insert Elements\n(2) Delete Element\n(3) Search Element\n(4) Display Inorder Traversal\n(5) Display Preorder Traversal\n(6) Display Postorder Traversal\n(7) Display Depth of Tree\n(8) Display Mirror Image of Tree\n(9) Display Leaf Nodes of Tree\n(10) Exit ---> ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            cout << "Enter elements in BST:-" << endl;
            insert();
            break;
        case 2:
            if (BST_check())
            {
                int num;
                cout << "Enter the number to delete: ";
                cin >> num;
                if (search(num))
                {
                    deleteNode(num);
                    cout << "Deleted Successfully" << endl;
                }
            }
            break;
        case 3:
            if (BST_check())
            {
                cout << "Enter the number to search: ";
                int num;
                cin >> num;
                search(num);
            }
            break;
        case 4:
            if (BST_check())
            {
                cout << "Inorder Traversal for given Tree is" << endl;
                rin_travers(root);
                cout << endl;
            }
            break;
        case 5:
            if (BST_check())
            {
                cout << "Preorder Traversal for given Tree is" << endl;
                rpre_travers(root);
                cout << endl;
            }
            break;
        case 6:
            if (BST_check())
            {
                cout << "Postorder Traversal for given Tree is" << endl;
                rpost_travers(root);
                cout << endl;
            }
            break;
        case 7:
            if (BST_check())
            {
                cout << "Depth of Tree is " << depth(root) - 1 << endl;
            }
            break;
        case 8:
            if (BST_check())
            {
                cout << "Mirror Image of Tree is" << endl;
                Mirror_BST(root);
                rin_travers(root);
                Mirror_BST(root);
                cout << endl;
            }
            break;
        case 9:
            if (BST_check())
            {
                cout << "Leaf Nodes of Tree are" << endl;
                leaf(root);
                cout << endl;
            }
            break;
        case 10:
            cout << "Thank You" << endl;
            ak = 1;
            break;
        default:
            cout << "Enter a Valid Choice" << endl;
        }
    }
};

int main()
{
    BST tree;
    tree.controlBST();
}