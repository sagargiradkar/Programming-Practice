#include<iostream>
using namespace std;
class circularQueue{
    private:
        int *arr;
        int front,rear,size;
    public:
        circularQueue();
        void insertion(int num);
        void deletion();
        void display();
        void startQueue();
};

circularQueue::circularQueue(){
    front=-1;
    rear=-1;
    cout<<"This is demonstration of a Circular Queue"<<endl;
    cout<<"\nEnter size of Circular Queue: ";
    cin>>size;
    arr=new int[size];
};

void circularQueue::insertion(int num){
    if((front==0 && rear==size-1) || (rear==front-1)){
        cout<<"\nCircular Queue is Full"<<endl;
    }
    else if(rear==size-1 && front!=0){
        rear=0;
        arr[rear]=num;
    }
    else{
        if(front==-1){
            front=0;
        }
        rear++;
        arr[rear]=num;
    }
};

void circularQueue::deletion(){
    if(front==-1 && rear==-1){
        cout<<"\nCircular Queue is Empty"<<endl;
        return;
    }
    cout<<"\nDeleted element is "<<arr[front]<<endl;
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else if(front==size-1){
        front=0;
    }
    else{
        front++;
    }
};
        
void circularQueue::display(){
    if(front==-1 && rear==-1){
        cout<<"\nCircular Queue is Empty"<<endl;
        cout<<"Value of front: "<<front<<endl<<"Value of rear: "<<rear<<endl;
        return;
    }
    cout<<"\nElements in Circular Queue are"<<endl;
    if(rear>=front){
        for(int i=front;i<=rear;i++){
            cout<<"("<<i<<") "<<arr[i]<<"  ";
        }
    }
    else if(front>rear){
        for(int i=front;i<size;i++){
            cout<<"("<<i<<") "<<arr[i]<<"  ";
        }
        for(int i=0;i<=rear;i++){
            cout<<"("<<i<<") "<<arr[i]<<"  ";
        }
    }          
    cout<<endl;
    cout<<"Value of front: "<<front<<endl<<"Value of rear: "<<rear<<endl;
};
    
void circularQueue::startQueue(){
    int a=0,choice;
    while(a==0){
        cout<<"\nEnter your choice:\n(1) Enqueue\n(2) Dequeue\n(3) Display\n(4) Exit -------------->";
        cin>>choice;
        switch(choice){
            case 1:int n;
            cout<<"\nEnter element to insert: ";
            cin>>n;
            insertion(n);
            break;
            case 2:deletion();
            break;
            case 3:display();
            break;
            case 4:cout<<"\nThank you"<<endl;
            a=1;
            break;
            default:cout<<"\nEnter a valid choice"<<endl;
        }
    }
};

int main()
{
    circularQueue cQueue;
    cQueue.startQueue();   
}