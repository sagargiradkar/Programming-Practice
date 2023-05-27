#include<iostream>
#include<iomanip>

using namespace std;
struct Student{
	string name;
	int rollNo;
	float sgpa;
};

class SEIT{
	private:
		int n,flag=0;
		struct Student stud[100];
		struct Student clone[100];
	public:
		void getInfo();
		void showData();
		void bubbleSort();
		void insertionSort();
		void linearSearch();
		void binarySearch();
		void lowerCase();
		int Partition(int left,int right);
		int QuickSort(int left,int right);
		void QuickPrint();
};

void SEIT::getInfo(){
	int i;
	cout<<"Enter number of students to add in Student Database: ";
	cin>>n;
	for(i=0;i<n;i++){
		cout<<"\nEnter information of student no."<<i+1<<" : "<<endl;
		while(true){
			cout<<"Enter Name: ";
			cin>>stud[i].name;
			int check=0;
			for(int j=0;j<(stud[i].name).length();j++){
				if(((stud[i].name)[j]>=97 && (stud[i].name)[j]<=122)||((stud[i].name)[j]>=65 && (stud[i].name)[j]<=90)){
				}
				else{
					cout<<"\nEnter a valid name\n"<<endl;
					check++;
					break;
				}
			}
			if(check==0){
				break;
			}
		}
		clone[i].name=stud[i].name;
		cout<<"Enter Roll no.: ";
		cin>>stud[i].rollNo;
		clone[i].rollNo=stud[i].rollNo;
		while(true){
			cout<<"Enter SGPA: ";
			cin>>stud[i].sgpa;
			if(stud[i].sgpa>=0 && stud[i].sgpa<=10){
				break;
			}
			else{
				cout<<"\nEnter a valid SGPA from 0 to 10\n"<<endl;
			}
		}
		clone[i].sgpa=stud[i].sgpa;
	}
	cout<<endl;
};

void SEIT::lowerCase(){
	copy(stud,stud+n,clone);
	for(int i=0;i<n;i++){
		string a=clone[i].name;
		for(int j=0;j<a.length();j++){
			if(a[j]>=97 && a[j]<=122){
				a[j]=char((int(a[j]))-32);
			}
		}
		clone[i].name=a; 
	}
};
		
void SEIT::showData(){
	int i;
	cout<<setfill(' ')<<left<<setw(10)<<"Name"<<setfill(' ')<<left<<setw(10)<<"Roll No"<<"SGPA"<<endl;
	for(i=0;i<n;i++){
		cout<<setfill(' ')<<left<<setw(10)<<stud[i].name<<setfill(' ')<<left<<setw(10)<<stud[i].rollNo<<stud[i].sgpa<<endl;
	}
};

void SEIT::bubbleSort(){
	int i,j,sp=0;
	Student temp;
    for(i=0;i<(n-1);i++)
    {   
  	    sp=0;
        for(j=0;j<(n-i-1);j++)
        {
        if(stud[j].rollNo>stud[j+1].rollNo)
        {
            temp=stud[j+1];
            stud[j+1]=stud[j];
            stud[j]=temp;
            sp++;
        }
        }
        if(sp==0)
        break;
    }
};

void SEIT::insertionSort(){
	int i,j;
	if(flag==1){
    	copy(stud,stud+n,clone);
    	flag=0;
	}
	Student temp,temp2;
	for(i=0;i<(n-1);i++){
		temp=stud[i+1];
		temp2=clone[i+1];
		j=i;
		while(j>=0 && clone[j].name>temp2.name){
			stud[j+1]=stud[j];
			clone[j+1]=clone[j];
			j--;
		}
		stud[j+1]=temp;
		clone[j+1]=temp2;
	}
};

void SEIT::linearSearch(){
	float s;
	int count=1;
	cout<<"Enter the SGPA: ";
	cin>>s;
	for(int i=0;i<n;i++){
		if(s==stud[i].sgpa){
				if(count==1){
					cout<<"Students of SGPA "<<s<<" :-"<<endl;
				}
			cout<<count<<"."<<stud[i].name<<endl;
			count++;
		}
	}
	if(count==1){
		cout<<"No students found of SGPA "<<s<<endl;
	}
};

void SEIT::binarySearch(){
	flag=1;
	insertionSort();
	int c1=1,mid,left=0,right=n-1,flag=0;
	string key;
	cout<<"Enter the name of student: ";
	cin>>key;
	while(left<=right){
		mid=(left+right)/2;
		if(stud[mid].name==key){
			cout<<"Student name: "<<stud[mid].name<<endl;
			cout<<"Roll No:"<<stud[mid].rollNo<<endl;
			cout<<"SGPA: "<<stud[mid].sgpa<<endl;
			flag=1;
			break;
		}
		if(stud[mid].name>key){
			right=mid-1;
		}
		else{
			left=mid+1;
		}
	}
	if(flag!=0){
		while(true){
			if(stud[mid].name==stud[mid+c1].name){
				cout<<"Student name: "<<stud[mid+c1].name<<endl;
				cout<<"Roll No:"<<stud[mid+c1].rollNo<<endl;
				cout<<"SGPA: "<<stud[mid+c1].sgpa<<endl;
				c1++;
			}
			else{
				break;
			}
		}
		c1=1;
		while(true){
			if(mid-c1>=0 && stud[mid].name==stud[mid-c1].name){
				cout<<"Student name: "<<stud[mid-c1].name<<endl;
				cout<<"Roll No:"<<stud[mid-c1].rollNo<<endl;
				cout<<"SGPA: "<<stud[mid-c1].sgpa<<endl;
				c1++;
			}
			else{
				break;
			}
		}
	}
	else{
		cout<<"No student found of name '"<<key<<"'"<<endl;
	}
};
	
int SEIT::Partition(int left,int right){
	float pivot=stud[right].sgpa;
	int i=left,j=right-1;
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
	swap(stud[i],stud[right]);
	return i;
};

int SEIT::QuickSort(int left,int right){
	if(left>=right){
		return 0;
	}
	else{
		int p=Partition(left,right);
		QuickSort(left,p-1);
		QuickSort(p+1,right);
		return 0;
	}
};
	
void SEIT::QuickPrint(){
	QuickSort(0,n-1);
	cout<<"Top 10 Toppers are as follows:"<<endl<<"   ";
	cout<<setfill(' ')<<left<<setw(10)<<"Name"<<setfill(' ')<<left<<setw(10)<<"Roll No"<<"SGPA"<<endl;
	int count=0,j=1;
	for(int i=n-1;i>=0;i--){
		if(((stud[i].sgpa)!=(stud[i+1].sgpa)) && (i!=(n-1))){
			j++;
			count++;
		}
		if(count==10){
			break;
		}
		cout<<j<<") ";
		cout<<setfill(' ')<<left<<setw(10)<<stud[i].name<<setfill(' ')<<left<<setw(10)<<stud[i].rollNo<<stud[i].sgpa<<endl;
	}
};
	
int main(){
	SEIT obj;
	obj.getInfo();
	int i=0,choice;
	while(i==0){
		cout<<"\nEnter your choice:\nShow List of Students sorted according to Roll no (1)\nShow List of Students sorted Alphabetically (2)\nSearch Students according to SGPA (3)\nSearch a Particular Student (4)\nShow Top 10 Toppers of class (5)\nExit (6)------------>";
		cin>>choice;
			cout<<endl;
		switch(choice){
			case 1: obj.bubbleSort();
			obj.showData();
			break;
			case 2: obj.lowerCase(); 
			obj.insertionSort();
			obj.showData();
			break;
			case 3: obj.linearSearch();
			break;
			case 4: obj.binarySearch();
			break;
			case 5: obj.QuickPrint();
			break;
			case 6: cout<<"Thank you"<<endl;
			i=1;
			break;
			default: cout<<"Enter a valid choice"<<endl;
		}
	}
}	