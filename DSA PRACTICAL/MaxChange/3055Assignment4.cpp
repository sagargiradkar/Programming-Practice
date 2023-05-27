#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Tnode
{
  public:
    char ch;
    Tnode *left;
    Tnode *right;
};

class Snode
{
  public:
    Tnode *ptrval;
    Snode *nxt;
};

class Stack
{
  public:
    Snode *top;

  public:
    Stack();
    void push(Tnode *root);
    Tnode *pop();
};

Stack::Stack()
{
    top = NULL;
};

void Stack::push(Tnode *root)
{
    Snode *temp;
    temp = new Snode;
    temp->ptrval = root;
    if (top == NULL)
    {
        temp->nxt = NULL;
        top = temp;
    }
    else
    {
        temp->nxt = top;
        top = temp;
    }
};

Tnode *Stack::pop()
{
    Tnode *t;
    if (top == NULL)
    {
        return NULL;
    }
    else
    {
        t = top->ptrval;
        top = top->nxt;
        return (t);
    }
};

class Exp_tree
{
  private:
    Tnode *root;
    string postfix, prefix;
    int sk;

  public:
    void creat_post();
    void creat_pre();
    bool exp_check(string str);
    void rpre_travers(Tnode *);
    void rpost_travers(Tnode *);
    void rin_travers(Tnode *);
    void ipre_travers(Tnode *);
    void ipost_travers(Tnode *);
    void iin_travers(Tnode *);
    void controlExpTree();
};

void Exp_tree::creat_post()
{
    cout << "\nEnter the postfix expression: ";
    cin.ignore();
    getline(cin, postfix);
    int length = postfix.length();
    int c = count(postfix.begin(), postfix.end(), ' ');
    remove(postfix.begin(), postfix.end(), ' ');
    postfix.resize(length - c);
    Stack s;
    for (int i = 0; i < postfix.length(); i++)
    {
        root = new Tnode;
        root->ch = postfix[i];
        root->left = NULL;
        root->right = NULL;
        if ((postfix[i] >= 'a' && postfix[i] <= 'z') || (postfix[i] >= 'A' && postfix[i] <= 'Z'))
        {
            s.push(root);
        }
        else
        {
            root->right = s.pop();
            root->left = s.pop();
            s.push(root);
        }
    }
    root = s.pop();
};

bool Exp_tree::exp_check(string str)
{
    int l = str.length() - 1;
    for (int i = 0; i <= l; i++)
    {
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')
        {
        }
        else
        {
            cout << "\nInvalid Symbol or Numbers are not allowed for required Expression" << endl;
            return false;
        }
    }
    if (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/' || str[0] == '^')
    {
        cout << "\nEnter a valid Expression" << endl;
        return false;
    }
    else if ((str[l] >= 'a' && str[l] <= 'z') || (str[l] >= 'A' && str[l] <= 'Z'))
    {
        cout << "\nEnter a valid Expression" << endl;
        return false;
    }
    else
    {
        return true;
    }
};

void Exp_tree::creat_pre()
{
    cout << "\nEnter the prefix expression: ";
    cin.ignore();
    getline(cin, prefix);
    int length = prefix.length();
    int c = count(prefix.begin(), prefix.end(), ' ');
    remove(prefix.begin(), prefix.end(), ' ');
    prefix.resize(length - c);
    reverse(prefix.begin(), prefix.end());
    Stack s;
    for (int i = 0; i < prefix.length(); i++)
    {
        root = new Tnode;
        root->ch = prefix[i];
        root->left = NULL;
        root->right = NULL;
        if ((prefix[i] >= 'a' && prefix[i] <= 'z') || (prefix[i] >= 'A' && prefix[i] <= 'Z'))
        {
            s.push(root);
        }
        else
        {
            root->left = s.pop();
            root->right = s.pop();
            s.push(root);
        }
    }
    root = s.pop();
};

void Exp_tree::rin_travers(Tnode *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        rin_travers(root->left);
        cout << root->ch;
        rin_travers(root->right);
    }
};

void Exp_tree::rpre_travers(Tnode *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        cout << root->ch;
        rpre_travers(root->left);
        rpre_travers(root->right);
    }
};

void Exp_tree::rpost_travers(Tnode *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        rpost_travers(root->left);
        rpost_travers(root->right);
        cout << root->ch;
    }
};

void Exp_tree::ipre_travers(Tnode *root)
{
    if (root == NULL)
    {
        cout << "Tree is Empty" << endl;
    }
    else
    {
        Stack s;
        do
        {
            while (root != NULL)
            {
                cout << root->ch;
                if (root->right != NULL)
                {
                    s.push(root->right);
                }
                root = root->left;
            }
            if (s.top != NULL)
            {
                root = s.pop();
            }
        } while (root != NULL);
    }
};

void Exp_tree::iin_travers(Tnode *root)
{
    int flag = 0;
    if (root == NULL)
    {
        cout << "Tree is Empty" << endl;
    }
    else
    {
        Stack s;
        do
        {
            while (root != NULL && flag == 0)
            {
                s.push(root);
                root = root->left;
            }
            root = s.pop();
            if (root != NULL)
            {
                cout << root->ch;
            }
            if (root != NULL && root->right != NULL)
            {
                flag = 0;
                root = root->right;
            }
            else
            {
                flag = 1;
            }
        } while (root != NULL);
    }
};

void Exp_tree::ipost_travers(Tnode *root)
{
    if (root == NULL)
    {
        cout << "Tree is Empty" << endl;
    }
    else
    {
        Stack s1, s2;
        s1.push(root);
        do
        {
            root = s1.pop();
            s2.push(root);
            if (root->left != NULL)
            {
                s1.push(root->left);
            }
            if (root->right)
            {
                s1.push(root->right);
            }
        } while (s1.top != NULL);
        while (s2.top != NULL)
        {
            root = s2.pop();
            cout << root->ch;
        }
    }
};

void Exp_tree::controlExpTree()
{
    cout << "This is Demonstration of Expression Tree" << endl;
    int flag = 0;
    while (flag == 0)
    {
        int flag2 = 0;
        while (true)
        {
            cout << "\nSelect the Input Expression Type:\n(1) Prefix Expression\n(2) Postfix Expression\n(3) Exit ---> ";
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                creat_pre();
                if (prefix.length() == 0)
                {
                    cout << "Enter a valid Prefix Expression" << endl;
                    flag2 = 1;
                    break;
                }
                if (exp_check(prefix))
                {
                }
                else
                {
                    flag2 = 1;
                }
                break;
            }
            else if (choice == 2)
            {
                creat_post();
                if (postfix.length() == 0)
                {
                    cout << "Enter a valid Postfix Expression" << endl;
                    flag2 = 1;
                    break;
                }
                if (exp_check(postfix))
                {
                }
                else
                {
                    flag2 = 1;
                }
                break;
            }
            else if (choice == 3)
            {
                cout << "\nThank you" << endl;
                flag2 = 1;
                flag = 1;
                break;
            }
            else
            {
                cout << "\nEnter a valid choice" << endl;
            }
        }
        while (flag2 == 0)
        {
            cout << "\nWhich Traversal Technique you want to see?\n(1) Iterative Pre-Order\n(2) Iterative In-Order\n(3) Iterative Post-Order\n(4) Recursive Pre-Order\n(5) Recursive In-Order\n(6) Recursive Post-Order\n(7) Change Expression\n(8) Exit ---> ";
            int c;
            cin >> c;
            switch (c)
            {
            case 1:
                cout << "\nExpression after Pre-Order Traversal is" << endl;
                rpre_travers(root);
                cout << endl;
                break;
            case 2:
                cout << "\nExpression after In-Order Traversal is" << endl;
                rin_travers(root);
                cout << endl;
                break;
            case 3:
                cout << "\nExpression after Post-Order Traversal is" << endl;
                rpost_travers(root);
                cout << endl;
                break;
            case 4:
                cout << "\nExpression after Pre-Order Traversal is" << endl;
                ipre_travers(root);
                cout << endl;
                break;
            case 5:
                cout << "\nExpression after In-Order Traversal is" << endl;
                iin_travers(root);
                cout << endl;
                break;
            case 6:
                cout << "\nExpression after Post-Order Traversal is" << endl;
                ipost_travers(root);
                cout << endl;
                break;
            case 7:
                flag2 = 1;
                break;
            case 8:
                cout << "\nThank you" << endl;
                flag2 = 1;
                flag = 1;
                break;
            default:
                cout << "\nEnter a valid choice" << endl;
            }
        }
    }
};

int main()
{
    Exp_tree obj;
    obj.controlExpTree();
}