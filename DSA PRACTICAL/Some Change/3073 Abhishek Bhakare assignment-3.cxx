#include<iostream>
#include<iomanip>
using namespace std;
class Queue{
    private:
		int Q[5],F,R,size=5;
	public:	
		Queue(){
			F=-1,R=-1;
		}
		void Enqueue();
		void Dequeue();
		void display();
};
void Queue::Enqueue(){//INSERTION
	int Num;	
	if(R==size-1){
		cout<<"YOU HAVE NO CHANCE TO INSERT,BECAUSE QUEUE IS ALMOST FULL "<<endl;
	}
	else{
		if(F==-1){ 
			F=0; 
		}
		R++;
		cout<<" ENTER THE NUMBER TO INSERT = ";
		cin>>Num;
		Q[R]=Num;	
	}
	cout<<"VALUE OF FRONT END="<<F<<endl;
	cout<<"VALUE OF REAR END="<<R<<endl;
}
void Queue::Dequeue(){//DELETION OF ELEMENT FROM QUEUE
	if(F==-1 && R==-1){
		cout<<"QUEUE IS ALREADY EMPTY"<<endl;
	}
	else{
		cout<<" NO: "<<Q[F]<<" IS DELETED FROM THE CIRCULAR QUEUE"<<endl;//FIRST ELEMENT IS DELETED
		//F++;
    	if(F==R){
    	    F=R=-1;
    	    cout<<"QUEUE IS ALREADY EMPTY:"<<endl;
    	}
    	else{
    	    F++;
    	}
	}
	cout<<"**VALUE OF FRONT END="<<F<<endl;
	cout<<"**VALUE OF REAR END="<<R<<endl;

}
void Queue::display(){
    if(F==-1 && R==-1){
        cout<<"QUEUE IS ALREADY EMPTY:"<<endl;
    }
    else{
    	int col_width=5;
    	cout<<left;
    	cout<<"*********************************CIRCULAR QUEUE AFTER OPERATION***************************"<<endl;
        cout<<"____________________________________________________"<<endl;
    	cout<<"INDEX VALUE:   ";
    	for(int i=F;i<=R;i++){
    		cout<<setw(col_width)<<i;
    	}
    	cout<<endl;
    	cout<<"--------------------------------------------------"<<endl;
    	cout<<"QUEUE VALUE:  ";
    	for(int i=F;i<=R;i++)	{		
    		cout<<setw(col_width)<<Q[i];
    	}
    	cout<<"\n_____________________________________________________"<<endl;
    }
}
int main(){
	Queue obj;
	int choice;
	while(true){
		cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< CIRCULAR QUEUE  MENU >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
		cout<<" 1] ENQUEUE  \n 2] DEQUEUE  \n 3] DISPLAY THE CIRCULAR QUEUE. \n 4] EXIT THE PROGRAM.\n_____________________ "<<endl;
		cout<<"ENTER CHOICE:";
		cin>>choice;
		cout<<endl;
		switch(choice){
			case 1:
			obj.Enqueue();
			obj.display();
			break;
			case 2:
			obj.Dequeue();
			obj.display();
			break;
			case 3:
			obj.display();
			break;
			case 4:
			cout<<"---------------------------------------------PROGRAM EXIT SUCCESSFULLY--------------------------------------"<<endl;
			break;
			default:
			cout<<"ENTER VALID CHOICE:"<<endl;
		}
		if(choice==4){
			break;
		}
	}
	return 0;
}
