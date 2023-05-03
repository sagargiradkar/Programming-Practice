#include <iostream>
#include <fstream>
#include<iomanip>
#include<string.h>
using namespace std;

class stud
{
    public:
    int rollNo;
    char name[20],division[20],address[20];
};

class f_stud
{
    public:
    void addData();
    void display();
    void search();
    void deleteStud();
    void controlFile();
};

void f_stud::addData(){
    fstream f;
    stud stud1;
    f.open("STUD", ios::app | ios::binary);
    if(!f.is_open()){
        cout<<"\nFile can't be open"<<endl;
        f.close();
        return;
    }
    cout<<"\nGive the Infromation of Students:-";
    int count;
    cout<<"Enter the number of students you want to add in Student's Database: ";
    cin>>count;
    for(int i=0;i<count;i++){
        cout<<"\nFor Student no."<<i+1<<":"<<endl;
        cout<<"Enter name: ";
        cin>>stud1.name;
        cout<<"Enter roll no: ";
        cin>>stud1.rollNo;
        cout<<"Enter division: ";
        cin>>stud1.division;
        cout<<"Enter address: ";
        cin>>stud1.address;
        f.write((char*)&stud1,sizeof(stud1));
    }
    cout<<"Data added Successfully!"<<endl;
    f.close();
};

void f_stud::display(){
    fstream f;
    stud stud1;
    f.open("STUD",ios::in | ios::binary);
    if(!f){
        cout<<"\nStudent's Database haven't created yet"<<endl;
    }
    else{
        cout<<"\nStudent's Database:-"<<endl;
        f.read((char*)&stud1,sizeof(stud1));
        cout<<"Name     Roll No.   Division   Address"<<endl;
        while(f){
    		cout<<setfill(' ')<<left<<setw(12)<<stud1.name<<setfill(' ')<<left<<setw(10)<<stud1.rollNo<<setfill(' ')<<left<<setw(9)<<stud1.division<<stud1.address<<endl;
            f.read((char*)&stud1,sizeof(stud1));
        }
    }
    f.close();
};

void f_stud::search(){
    fstream f;
    stud stud1;
    f.open("STUD",ios::in | ios::binary);
    if(!f){
        cout<<"\nStudent's Database haven't created yet"<<endl;
    }
    else{
        cout<<"\nEnter the name to search the student: ";
        int flag=0;
        char name[20];
        cin>>name;
        f.read((char*)&stud1,sizeof(stud1));
        while(f){
            if(strcasecmp(name,stud1.name)==0){
                cout<<"Student found\nName: "<<stud1.name<<"\nRoll no.: "<<stud1.rollNo<<"\nDivision: "<<stud1.division<<"\nAddress: "<<stud1.address<<endl;
                flag=1;
            }
            f.read((char*)&stud1,sizeof(stud1));
        }
        if(flag==0){
            cout<<"Student not found"<<endl;
        }
    }
    f.close();
};

void f_stud::deleteStud(){
    fstream f1,f2;
    stud stud1;
    f1.open("STUD",ios::in | ios::binary);
    if(!f1){
        cout<<"\nStudent's Database haven't created yet"<<endl;
        f1.close();
        return;
    }
    f2.open("TEMP",ios::out | ios::binary);
    if(!f2.is_open()){
        cout<<"\nFile can't be opened"<<endl;
        f2.close();
        return;
    }
    int roll,flag=0;
    cout<<"\nEnter the roll no. to delete the student: ";
    cin>>roll;
    f1.read((char*)&stud1,sizeof(stud1));
    while(!f1.eof()){
        if(stud1.rollNo==roll){
            flag=1;
        }
        else{
            f2.write((char*)&stud1,sizeof(stud1));
        }
        f1.read((char*)&stud1,sizeof(stud1));
    }
    f1.close();
    f2.close();
    if(flag==1){
        cout<<"Student info deleted"<<endl;
    }
    else{
        cout<<"Student not found"<<endl;
    }
    remove("STUD");
    rename("TEMP","STUD");
};

void f_stud::controlFile(){
    int flag=0,choice;
    cout<<"Welcome to Student Database Portal"<<endl;
    while(flag==0){
        cout<<"\nEnter your choice:\n(1) Add Students Information\n(2) Delete a Student's Information\n(3) Search a Student's Information\n(4) Display Student Information Database\n(5) Exit ---> ";
        cin>>choice;
        switch(choice){
            case 1:addData();
            break;
            case 2:deleteStud();
            break;
            case 3:search();
            break;
            case 4:display();
            break;
            case 5:cout<<"\nThank you"<<endl;
            flag=1;
            break;
            default:cout<<"\nEnter a valid choice"<<endl;
        }   
    }
};

int main(){
    f_stud s;
    s.controlFile();
}