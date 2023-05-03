#include <iostream>
using namespace std;
struct student{
	string name;
	int rollno;
	float sgpa;
};   
class Structure{
	struct student stud[100];
	private:int no;
     public:void read();
     void display();
     void Bubble_sort();
     void Insertion_sort();
     void Quick_print();
     int Quick_sort(int L,int R);
     int Partition(int L,int R);
     void display1();
     void Binary_search();
     void Linear_search();
};
void Structure::read(){//METHOD TO TAKE DATA FROM USER
	cout<<"ENTER THE TOTAL NUMBER OF STUDENT=";
	cin>>no;
	for(int i=0;i<no;i++){
		cout<<"ENTER THE NAME:";
	   	cin>>stud[i].name;
	   	cout<<"ENTER THE ROLL NO:";
	   	cin>>stud[i].rollno;
	   	cout<<"ENTER THE SGPA:";
    		cin>>stud[i].sgpa;
	}
}
void Structure::display(){//METHOD TO DISPLAY DATA OF STUDENT
	cout<<"*********************STUDENT DETAILS******************************"<<endl;
	cout<<"____________________________________________________________"<<endl;
	cout<<"    NAME                       ROLL NO                  SGPA "<<endl;
	for(int i=0;i<no;i++){
		cout<<stud[i].name<<"                        "<<stud[i].rollno<<"                       "<<stud[i].sgpa<<endl;
	}
	
}
void Structure::Bubble_sort(){//TO DISPLAY ROLL CALL LIST IN ACSENDING ORDER
    struct student Temp;
	for(int i=0;i<no-1;i++){
		for(int j=0;j<no-1;j++){
			if(stud[j].rollno>stud[j+1].rollno){
				Temp=stud[j];
				stud[j]=stud[j+1];
				stud[j+1]=Temp;
			}
		}
		
	}
	cout<<"*******************STUDENT ROLL NO LIST**************************"<<endl;
	cout<<"_________________________________________________________________"<<endl;
	cout<<"NAME                       ROLL NO                  SGPA "<<endl;
	for(int i=0;i<no;i++){
		cout<<stud[i].name<<"                     "<<stud[i].rollno<<"                     "<<stud[i].sgpa<<endl;
	}
}
void Structure::Insertion_sort(){//TO DISPLAY STUDENT NAMES ALPHABETICALLY
    int j;
    struct student key;
    for(int i=0;i<no-1;i++){
        key=stud[i+1];//KEY ELEMENT AT INDEX 1
        j=i;
        while(stud[j+1].name<stud[j].name && j>=0){//FOR COMPARING KEY ELEMENT WITH PREVIOUS ELEMENT 
            stud[j+1]=stud[j];//INTERCHANGING KEY ELEMENT TO LEFT POSITION
            stud[j]=key;
            j--;//USED TO REDUCE THE COMPARED ELEMENT POSITION BY 1
        }
    }
    cout<<"*********************STUDENTS LIST ACCORDING TO NAME*************************:"<<endl;
    cout<<"______________________________________________________________________________"<<endl;
	cout<<"NAME                       ROLL NO                  SGPA "<<endl;
	for(int i=0;i<no;i++){
		cout<<stud[i].name<<"                          "<<stud[i].rollno<<"                  "<<stud[i].sgpa<<endl;
	}
}
void Structure::Linear_search(){//TO SEARCH PARTICULAR SGPA OF STUDENT
    float knum;
    int flag=0;
    cout<<"ENTER THE SGPA TO SEARCH=";
    cin>>knum;
    for(int i=0;i<no;i++){
        if(stud[i].sgpa==knum){
            cout<<"NAME                       ROLL NO                  SGPA "<<endl;
	    	cout<<stud[i].name<<"                       "<<stud[i].rollno<<"                   "<<stud[i].sgpa<<endl;
            flag++;
        }
        else{
        }
    }
    cout<<flag<<" STUDENT HAVE SAME SGPA:"<<endl;
}
int Structure::Partition(int L,int R){
	int pivot=stud[R].sgpa;
	int i=L,j=R-1;
	while(i<=j){
		while(stud[i].sgpa<pivot){
			i=i+1;
		}
		while(j>0 && stud[j].sgpa>pivot){
			j=j-1;
		}
		if(i<j){
			swap(stud[i],stud[j]);
		}
		j--;
	}
	swap(stud[i],stud[R]);
	return i;
};
int Structure::Quick_sort(int L,int R){
	if(L>=R){
		return 0;
	}
	else{
		int p=Partition(L,R);
		Quick_sort(L,p-1);
		Quick_sort(p+1,R);
		return 0;
	}
};
void Structure::Quick_print(){
	Quick_sort(0,no-1);
	display1();
};
void Structure::display1(){
	int k;
	cout<<"HOW MANY STUDENT TOPPERS LIST YOU WANT?:";
	cin>>k;
	cout<<"---------------------------------FIRST"<<k<<" TOPPERS OF A CLASS----------------"<<endl;
	cout<<"NAME                       ROLL NO                  SGPA "<<endl;
	for(int i=no-1;i>=no-k;i--){
		cout<<stud[i].name<<"                       "<<stud[i].rollno<<"                       "<<stud[i].sgpa<<endl;
	}
}
void Structure::Binary_search(){//TO SEARCH NAME OF PARTICULAR STUDENT
	int L=0,M,R=no-1,flag=0;
	string key1;
	cout<<"ENTER THE STUDENT NAME TO SEARCH=";
	cin>>key1;
	while(L<=R){
		M=(L+R)/2;
		if(stud[M].name==key1){
			cout<<"NAME:"<<stud[M].name<<" ";
			cout<<"ROLL NO:"<<stud[M].rollno<<" ";
			cout<<"MARKS:"<<stud[M].sgpa<<endl;
			flag=1;
			break;
		}
		if(stud[M].name>key1){
			R=M-1;
		}
		else{
			L=M+1;
		}
	}
	if(flag==0){
		cout<<"STUDENT NAME NOT FOUND."<<endl;
	}
}
int main() {
	Structure pot;
	int choice,flag=0;
	pot.read();
    pot.display();
   	while(true){
		cout<<"__________________________________MENU_____________________________"<<endl;
    	cout<<"1]DISPLAY ROLL NO CALL LIST\n2]DISPLAY STUDENT NAMES ALPHABETICALLY\n3]SEARCH SGPA OF PARTICULAR STUDENT\n4]SEARCH NAME OF PARTICULAR STUDENT\n5]DISPLAY FIRST TEN TOPPERS FROM  A CLASS\n6]EXIT"<<endl;
   		cout<<"ENTER THE CHOICE:";
   		cin>>choice;
   		switch(choice){
	   		case 1:
    		pot.Bubble_sort();
    		break;
	   		case 2:
	   		pot.Insertion_sort();
	   		flag=2;
	    	break;
	    	case 3:
	    		pot.Linear_search();
	    		break;
	    	case 4:
	    	if(flag==2){
	    	    pot.Binary_search();
	   		    break;
	   		}
	   	else{ 
	   	    pot.Insertion_sort();
		    pot.Binary_search();
    		    break;
  	   		}
	    	case 5:
	    	pot.Quick_print();
	    	break;
    	}
 	   	if(choice==6){
    		cout<<"________________________________________EXIT SUCCESSFULLY______________________________________"<<endl;
  	   		break;
	   	}
    }
}

