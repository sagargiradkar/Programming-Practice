#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
class stud{
    public:
    int Rollno;
    char name[20],Div[5],Addrs[100],name1[20]; 
};
class f_stud{
    public:
    fstream f,f1;
    stud stud1,stud2;
    void create();
    void display();
    void Search();
    void Update();
    void Add_Data();
    void Delete();
};
void f_stud::create(){
    char ans;
    f.open("STUD", ios::out | ios::binary);
    if(!f.is_open()){
        cout <<"File can not be opened";
        exit(0);
    }
    cout <<endl<<"INPUT INFO OF STUDENT IN FILE:- "<<endl;
    do{
        cout<<"Enter Rollno:";
        cin >> stud1.Rollno;
        cout<<"Enter name of student:";
        cin>>stud1.name;
        cout<<"Enter the Div:";
        cin>>stud1.Div;
        cout<<"Enter the Address:";
        cin>>stud1.Addrs;
        f.write((char*)&stud1,sizeof(stud1));//WRITING DATA INTO THE FILE
        cout<<"Do you want to continue (Yes/No):";
        cin>>ans;
        cout<<"================================================\n";
      }while(ans=='y' || ans=='Y');
      f.close();
}

void f_stud::display(){
    f.open("STUD", ios::in |ios::binary); //OPENING FILE 
    f.read((char*)&stud1,sizeof(stud1));//READING FILE
      cout<<"===========================STUDENT RECORDS===============================\n";
      cout<<"Roll no \t Name \t\tDiv \t\tAddress\n"; 
      while(f){   //while(!f.eof()){
        cout<<stud1.Rollno<<"\t\t"<<stud1.name<<"\t\t"<<stud1.Div<<"\t\t"<<stud1.Addrs<<"\n";
        f.read((char*)&stud1,sizeof(stud1));   
      }
      cout<<"\n========================================================================\n";
    f.close();
}
void f_stud::Search(){
	string key;
	int flag=0;
	f.open("STUD", ios::in | ios::binary);
	cout<<"Enter the name of student to search:";
	cin>>key;
	while(f){
		f.read((char*)&stud1,sizeof(stud1)); 
		if(stud1.name==key){
			flag=1;
			break;
		}
    else{
      flag=-1;
    }
	}
	if(flag==1){
		cout<<"==================Found Student Details========================"<<endl;
    cout<<"Roll no \t Name \t\tDiv \t\tAddress\n";
    cout<<stud1.Rollno<<"\t\t"<<stud1.name<<"\t\t"<<stud1.Div<<"\t\t"<<stud1.Addrs<<"\n";
    f.read((char*)&stud1,sizeof(stud1));
    cout<<"==============================================================="<<endl;   
	}
	else{
		cout<<"Not found\n";
	}
	f.close();
}
void f_stud::Update(){
  string key;
  ifstream f;
  f.open("STUD", ios::in | ios::binary);
  ofstream fout;
  fout.open("Temp",ios::out | ios::binary);
  if(!f.is_open()){
    cout <<"File cannot be opened";
    exit(0);
  }
  else{
    cout<<"Enter the name of student to update:";
    cin>>key;
    f.read((char*)&stud1,sizeof(stud1)); 
    while(f){
      if(stud1.name==key){
        cout<<"==================Found Student Details========================"<<endl;
        cout<<"Roll no \t Name \t\tDiv \t\tAddress\n";
        cout<<stud1.Rollno<<"\t\t"<<stud1.name<<"\t\t"<<stud1.Div<<"\t\t"<<stud1.Addrs<<"\n";
        f.read((char*)&stud1,sizeof(stud1));
        cout<<"==============================================================="<<endl;
        cout <<endl<<"INPUT INFO OF STUDENT :- "<<endl;
            cout<<"Enter Rollno:";
            cin >> stud1.Rollno;
            cout<<"Enter name of student:";
            cin>>stud1.name;
            cout<<"Enter the Div:";
            cin>>stud1.Div;
            cout<<"Enter the Address:";
            cin>>stud1.Addrs;
            fout.write((char*)&stud1,sizeof(stud1));
            cout<<"\n File updated successfully\n";
      }
      else{
         fout.write((char*)&stud1,sizeof(stud1));
      }
       f.read((char*)&stud1,sizeof(stud1)); 
	  }
    f.close();
    fout.close();
    remove("STUD");
    rename("Temp","STUD");
  }  
}
void f_stud::Add_Data(){
  int no;
  f.open("STUD", ios::app);
    if(!f.is_open())
    {
        cout <<"File can not be opened";
        exit(0);
    }
    cout<<"How many student data you want to append?:";
    cin>>no;
    cout <<endl<<"           INPUT INFO OF STUDENT :- "<<endl;
    for(int i=0;i<no;i++){
        cout<<"              Enter Rollno:";
        cin >> stud1.Rollno;
        cout<<"              Enter name of student:";
        cin>>stud1.name;
        cout<<"              Enter the Div:";
        cin>>stud1.Div;
        cout<<"              Enter the Address:";
        cin>>stud1.Addrs;
        f.write((char*)&stud1,sizeof(stud1));//writing into the main file
        cout<<"=====================================================================\n";
      }
      f.close();
}
void f_stud::Delete(){
  string key;
  ifstream f;
  f.open("STUD", ios::in);
  ofstream fout;
  fout.open("Temp",ios::out);
  cout<<"Enter the name of student to delete record:";
    cin>>key;
  if(!f.is_open()){
    cout <<"File can not be opened";
    exit(0);
  }
  else{
    f.read((char*)&stud1,sizeof(stud1)); 
    while(f){
      
      if(stud1.name==key){
          cout<<"===============Record found and deleted========================\n";
      }
      else{
         fout.write((char*)&stud1,sizeof(stud1));
      }
      f.read((char*)&stud1,sizeof(stud1));
	  }
    f.close();
    fout.close();
    remove("STUD");
    rename("Temp","STUD");
  }  

}
int main(){
 	f_stud S;//object of class
  int choice; 
  while(true){
    cout<<" \n=========================FILE OPERATION=========================\n";
    cout<<"\t1]Create file \n________________________________________________________________\n\t2]Display file \n________________________________________________________________\n\t3]Search \n________________________________________________________________\n\t4]Add more records \n________________________________________________________________\n\t5]Delete record \n________________________________________________________________\n\t6]Update record \n________________________________________________________________\n\t7]Exit \n________________________________________________________________\n\tEnter your choice:";
    cin>>choice;
    cout<<"________________________________________________________________\n";
    switch(choice){
      case 1:
        S.create();
        break;
      case 2:
        S.display();
        break;
      case 3:
        S.Search();
        break;
      case 4:
        S.Add_Data();
        break;
      case 5:
        S.Delete();
        break;
      case 6:
        S.Update();	//Modify()
        break;
      case 7:
        break;
      default:cout<<"Enter the valid choice."<<endl;
    }
    if(choice==7){
      cout<<"===========================Exit Successfully=====================================\n";
      break;
    }
  }
  return 0;
}