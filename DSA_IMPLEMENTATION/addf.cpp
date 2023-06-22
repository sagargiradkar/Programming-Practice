#include<iostream>
using namespace std;
class Add{
    public:
    int fun1(int n);
    int fun2(int n);
    int fun3(int n);
    int n;
};
int Add::fun1(int n){
    return n*(n+1)/2;
}

int Add::fun2(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum=sum+i;
    }
    return sum;
}

int Add::fun3(int n){
    int sum=0;
    for(int i=0;i<=n;i++){
        for(int j=1;j<=i;j++)
        sum++;
    }
    return sum;
}
int main(){
    Add obj;
    cout<<"Addition of N Natural Number "<<endl;
    cout<<"Enter the Number :";
    cin>>obj.n;
    cout<<"1.Call fun1"<<endl;
    cout<<"2.call fun2"<<endl;
    cout<<"3.call fun3"<<endl;
    int ch;
    cin>>ch;
    int ans;
  //  do{
    switch(ch){
        case 1:ans= obj.fun1(obj.n);
            cout<<ans<<endl;
            break;
        case 2:ans= obj.fun2(obj.n);
            cout<<ans<<endl;
            break;
        case 3:ans= obj.fun2(obj.n);
            cout<<ans<<endl;
            break;
        default:exit(0);
    }
    //}while(ch!=3);

    return 0;

}
