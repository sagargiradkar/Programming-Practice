#include<iostream>
using namespace std;
class Queue{
        private :
                int queue[6],front ,rear,size=6;
                public:
                Queue(){
                        front=-1;
                        rear=-1;
                }
                void insertion();
                void deletion();
                void display();
                 };
       
void Queue::insertion(){

        int num;
        if(front ==-1 && rear==-1){
        front =rear=0;
        cout<<"Enter element :";
        cin>>num;
        queue[rear]=num;
        }
        else if((rear+1)%size==front){
                cout<<"Queue is full"<<endl;
                }
          else{
          rear=(rear+1)%size;
          cout<<"Enter Number :";
          cin>>num;
          queue[rear]=num;
          }
          
          }
void Queue::deletion(){
        if(front==-1 && rear==-1){
        cout<<"Queue is Empty"<<endl;
        }
        else if(front==rear){
                cout<<"No." << queue[front]<<"is deleted"<<endl;
                front=(front+1)%size;
                front=rear=-1;
                }
                else{
                cout<<"No "<<queue[front]<<" is deleted "<<endl;
                front=(front+1)%size;
                }
                }
void Queue::display(){
     int i=front;
     cout<<"Front Pointer is ="<<front <<endl<<"Rear Pointer is ="<<rear<<endl;
     if(front ==-1 && rear==-1){
     }
     else
     {
     cout<<"Queue Display Is :"<<endl;
     cout<<"Queue Value ";
     while(i!=rear){
        cout<<queue[i]<<" ";
        i=(i+1)%size;
        }
        cout<<queue[i]<<" ";
        }
}
int main()
        {
               Queue obj;
	int choice;
	cout<<"\n ***** Program For Circular Queue ***** "<<endl;

	do
	{
		cout<<"\n <<< Queue Menu >>> "<<endl;
		cout<<" 1. Enqueue (Insert No.) \n 2. Dequeue (Delete No.) \n 3. Exit the program. "<<endl;
		cout<<"\n Enter the Operation to be Performed = ";
		cin>>choice;

		switch(choice)
		{
			case 1:
			obj.insertion();
			obj.display();
			break;
			case 2:
			obj.deletion();
			obj.display();
			break;
		}
	}while(choice!=3);
	cout<<"\n >>>>> Program Exited Successfully >>>>> \n"<<endl;
return 0;
                }
          
