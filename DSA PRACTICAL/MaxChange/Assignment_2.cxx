#include<iostream>
//#include<bits/stdc++.h>
using namespace std;

template<class T>
class Node{
  public:
    T data;
    Node<T> *next;
};

template<class T>
class Stack{
  public:
    Node<T> *top;    
  public:    
    Stack(){
        top=NULL;
    };
    void Push(T c);
    T Pop();
};

template<class T>
void Stack<T>::Push(T c){
    if (top == NULL){
        top = new Node<T>;
        top->data = c;
        top->next = NULL;
    }
    else{
        Node<T> *temp = new Node<T>;
        temp->next = top;
        temp->data = c;
        top = temp;
    }
};

template<class T>
T Stack<T>::Pop(){
    Node<T> *temp = top;
    T c = top->data;
    top = top->next;
    free(temp);
    return c;
};

class Expression{
  private:
    string infix, postfix, prefix;
    int ak = 0, sk = 0;

  public:
    void input();
    void infix_check();
    void infix_to_postfix();
    void eval_postfix();
    void infix_to_prefix();
    void eval_prefix();
    int priority(char a);
    string showExp(string str);
    void controlExp();
};

void Expression::input(){
    infix = "";
    postfix = "";
    prefix = "";
    cout << "\nEnter the Infix Expression: ";    
    if (sk != 0){
        cin.ignore();
    }
    sk = 1;
    getline(cin, infix);   
    int length = infix.length();
    int c = count(infix.begin(), infix.end(), ' ');
    remove(infix.begin(), infix.end(), ' ');
    infix.resize(length - c);
    infix_check();
};

void Expression::infix_check(){
    ak = 0;
    int l = infix.length() - 1,flag = 0;
    for (int i = 0; i <= l; i++){
        if ((infix[i] >= 48 && infix[i] <= 57) || (infix[i] >= 65 && infix[i] <= 90) || (infix[i] >= 97 && infix[i] <= 122) || infix[i] == '(' || infix[i] == ')' || infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^'){
        }
        else{
            cout << "\nSymbol '" << infix[i] << "' is not allowed for required equation" << endl;
            flag = 1;
            sk = 0;
            break;
        }
    }
    if (flag == 0){
        if (infix[0] == '+' || infix[0] == '-' || infix[0] == '*' || infix[0] == '/' || infix[0] == '^'){
            cout << "\nEnter a valid Infix Expression" << endl;
            sk = 0;
        }
        else if (infix[l] == '+' || infix[l] == '-' || infix[l] == '*' || infix[l] == '/' || infix[l] == '^'){
            cout << "\nEnter a valid Infix Expression" << endl;
            sk = 0;
        }
        else{
            ak = 1;
        }
    }
};

void Expression::infix_to_postfix(){
    Stack<char> stk;
    for (int i = 0; i < infix.length(); i++){
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')){
            postfix = postfix + infix[i];
            postfix = postfix + ' ';
        }
        if (infix[i] >= '0' && infix[i] <= '9'){
            postfix = postfix + infix[i];
            if (infix[i + 1] >= '0' && infix[i + 1] <= '9'){
            }
            else{
                postfix = postfix + ' ';
            }
        }
        if (infix[i] == '('){
            stk.Push(infix[i]);
        }
        if (infix[i] == ')'){
            while (stk.top->data != '('){
                char c = stk.Pop();
                postfix = postfix + c;
                postfix = postfix + ' ';
            }
            stk.Pop();
        }
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^'){
            if (stk.top == NULL){
                stk.Push(infix[i]);
            }
            else{
                char c = stk.Pop();
                int flag = 0;
                while (priority(c) >= priority(infix[i])){
                    postfix = postfix + c;
                    postfix = postfix + ' ';
                    flag = 1;
                    if (stk.top != NULL){
                        c = stk.Pop();
                        flag = 0;
                    }
                    else{
                        break;
                    }
                }
                if (flag == 0){
                    stk.Push(c);
                    stk.Push(infix[i]);
                }
                else{
                    stk.Push(infix[i]);
                }
            }
        }
    }
    while (stk.top != NULL){
        postfix = postfix + stk.Pop();
        postfix = postfix + ' ';
    }
    cout << "\nPostfix Expression is " << showExp(postfix) << endl;
};

void Expression::eval_postfix(){
    int l = postfix.length(), j = 0, flag = 0;
    float arr[50];
    for (int i = 0; i < l; i++){
        if ((postfix[i] >= 'a' && postfix[i] <= 'z') || (postfix[i] >= 'A' && postfix[i] <= 'Z')){
            float num;
            cout << "\nEnter value for variable " << postfix[i] << " : ";
            cin >> num;
            arr[j] = num;
            j++;
        }
        else if (flag == 1){
            float a = float(postfix[i] - 48);
            float b = arr[j];
            a = (b * 10) + a;
            arr[j] = a;
            flag = 0;
            j++;
            if (postfix[i + 1] >= '0' && postfix[i + 1] <= '9'){
                flag = 1;
                j--;
            }
        }
        else if (postfix[i] >= '0' && postfix[i] <= '9'){
            arr[j] = float(postfix[i] - 48);
            j++;
            if (postfix[i + 1] >= '0' && postfix[i + 1] <= '9'){
                flag = 1;
                j--;
            }
        }
    }
    Stack<float> stk;
    int k = 0;
    for (int i = 0; i < postfix.length() - 1; i++){
        if (postfix[i + 1] == ' '){
            if ((postfix[i] >= 'a' && postfix[i] <= 'z') || (postfix[i] >= 'A' && postfix[i] <= 'Z') || (postfix[i] >= '0' && postfix[i] <= '9')){
                stk.Push(arr[k]);
                k++;
            }
            else{
                float a = stk.Pop();
                float b = stk.Pop();
                if (postfix[i] == '+'){
                    stk.Push(b + a);
                }
                else if (postfix[i] == '-'){
                    stk.Push(b - a);
                }
                else if (postfix[i] == '*'){
                    stk.Push(b * a);
                }
                else if (postfix[i] == '/'){
                    stk.Push(b / a);
                }
                else{
                    stk.Push(pow(b, a));
                }
            }
        }
    }
    cout << "\nResult of Postfix Expression Evaluation is " << stk.Pop() << endl;
};

int Expression::priority(char a){
    if (a == '+' || a == '-'){
        return 1;
    }
    else if (a == '*' || a == '/'){
        return 2;
    }
    else if (a == '^'){
        return 3;
    }
    else{
        return 0;
    }
};

void Expression::infix_to_prefix(){
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.length(); i++){
        if (infix[i] == '('){
            infix[i] = ')';
        }
        else if (infix[i] == ')'){
            infix[i] = '(';
        }
    }
    Stack<char> stk;
    for (int i = 0; i < infix.length(); i++){
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')){
            prefix = prefix + infix[i];
            prefix = prefix + ' ';
        }
        if (infix[i] >= '0' && infix[i] <= '9'){
            prefix = prefix + infix[i];
            if (infix[i + 1] >= '0' && infix[i + 1] <= '9'){
            }
            else{
                prefix = prefix + ' ';
            }
        }
        if (infix[i] == '('){
            stk.Push(infix[i]);
        }
        if (infix[i] == ')'){
            while (stk.top->data != '('){
                char c = stk.Pop();
                prefix = prefix + c;
                prefix = prefix + ' ';
            }
            stk.Pop();
        }
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^'){
            if (stk.top == NULL){
                stk.Push(infix[i]);
            }
            else{
                char c = stk.Pop();
                int flag = 0;
                while (priority(c) >= priority(infix[i])){
                    prefix = prefix + c;
                    prefix = prefix + ' ';
                    flag = 1;
                    if (stk.top != NULL){
                        c = stk.Pop();
                        flag = 0;
                    }
                    else{
                        break;
                    }
                }
                if (flag == 0){
                    stk.Push(c);
                    stk.Push(infix[i]);
                }
                else{
                    stk.Push(infix[i]);
                }
            }
        }
    }
    while (stk.top != NULL){
        prefix = prefix + stk.Pop();        
        prefix = prefix + ' ';
    }
    reverse(prefix.begin(), prefix.end());
    cout << "\nPrefix Expression is " << showExp(prefix) << endl;
};

void Expression::eval_prefix(){
    int g, len = prefix.length(),l = prefix.length(), j = 0, flag = 0;
    string sp;
    for (int i = prefix.length() - 1; i >= 0; i--){
        g = i;
        if (prefix[i] == ' '){
            g++;
            int last = 0;
            while (g < len){
                sp = sp + prefix[g];
                g++;
                last++;
            }
            sp = sp + ' ';
            len = len - last - 1;
        }
    }
    prefix = sp;
    float arr[50];
    for (int i = 0; i < l; i++){
        if ((prefix[i] >= 'a' && prefix[i] <= 'z') || (prefix[i] >= 'A' && prefix[i] <= 'Z')){
            float num;
            cout << "\nEnter value for variable " << prefix[i] << " : ";
            cin >> num;
            arr[j] = num;
            j++;
        }
        else if (flag == 1){
            float a = float(prefix[i] - 48);
            float b = arr[j];
            a = (b * 10) + a;
            arr[j] = a;
            flag = 0;
            j++;
            if (prefix[i + 1] >= '0' && prefix[i + 1] <= '9'){
                flag = 1;
                j--;
            }
        }
        else if (prefix[i] >= '0' && prefix[i] <= '9'){
            arr[j] = float(prefix[i] - 48);
            j++;
            if (prefix[i + 1] >= '0' && prefix[i + 1] <= '9'){
                flag = 1;
                j--;
            }
        }
        else if (prefix[i] == ' '){
        }
    }
    Stack<float> stk;
    int k = 0;
    for (int i = 0; i < prefix.length() - 1; i++){
        if (prefix[i + 1] == ' '){
            if ((prefix[i] >= 'a' && prefix[i] <= 'z') || (prefix[i] >= 'A' && prefix[i] <= 'Z') || (prefix[i] >= '0' && prefix[i] <= '9')){
                stk.Push(arr[k]);
                k++;
            }
            else{
                float a = stk.Pop();
                float b = stk.Pop();
                if (prefix[i] == '+'){
                    stk.Push(a + b);
                }
                else if (prefix[i] == '-'){
                    stk.Push(a - b);
                }
                else if (prefix[i] == '*'){
                    stk.Push(a * b);
                }
                else if (prefix[i] == '/'){
                    stk.Push(a / b);
                }
                else{
                    stk.Push(pow(a, b));
                }
            }
        }
    }
    cout << "\nResult of Prefix Expression Evaluation is " << stk.Pop() << endl;
};

string Expression::showExp(string str){
    int length = str.length();
    int c = count(str.begin(), str.end(), ' ');
    remove(str.begin(), str.end(), ' ');
    str.resize(length - c);
    return str;
};

void Expression::controlExp(){
    cout << "This is Demonstration of Expression Convertor and Evaluator" << endl;
    int flag1 = 0, choice1, choice2, choice3;
    while (flag1 == 0){
        while (true){
            input();
            if (ak == 1){
                break;
            }
        }
        while (true){
            cout << "\nEnter your choice: \n(1) Infix to Postfix Expression\n(2) Infix to Prefix Expression\n(3) Exit --->";
            cin >> choice1;
            if (choice1 == 1){
                infix_to_postfix();
                while (true){
                    cout << "\nDo you want to evaluate this Infix Expression?\n(1) Yes\n(2) No --->";
                    cin >> choice2;
                    if (choice2 == 1){
                        eval_postfix();
                        break;
                    }
                    else if (choice2 == 2){
                        cout << "\nOK" << endl;
                        break;
                    }
                    else{
                        cout << "\nEnter a valid choice" << endl;
                    }
                }
                break;
            }
            else if (choice1 == 2){
                infix_to_prefix();
                while (true){
                    cout << "\nDo you want to evaluate this Infix Expression?\n(1) Yes\n(2) No --->";
                    cin >> choice2;
                    if (choice2 == 1){
                        eval_prefix();
                        break;
                    }
                    else if (choice2 == 2){
                        cout << "\nOK" << endl;
                        break;
                    }
                    else{
                        cout << "\nEnter a valid choice" << endl;
                    }
                }
                break;
            }
            else if (choice1 == 3){
                break;
            }
            else{
                cout << "\nEnter a valid choice" << endl;
            }
        }
        while (true){
            cout << "\nDo you want to try another Infix Expression?\n(1) Yes\n(2) Exit --->";
            cin >> choice3;
            if (choice3 == 1){
                break;
            }
            else if (choice3 == 2){
                cout << "\nThank you" << endl;
                flag1 = 1;
                break;
            }
            else{
                cout << "\nEnter a valid choice" << endl;
            }
        }
    }
};

int main(){
    Expression exp1;
    exp1.controlExp();
}