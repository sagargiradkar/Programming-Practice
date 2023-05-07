#include<iostream>
#include<limits.h>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
        int v,e,temp;
        int **matrix;
        int *arr;
        string *depart;
    public:
        void createGraph();
        void primsAlgo();
        string toLowerCase(string str);
        void controlGraph();
};

void Graph::createGraph(){
    cout<<"\nEnter the Information of College Campus:-\n"<<endl;
    cout<<"Enter the number of Departments: ";
    cin>>v;
    cout<<"Enter the number of Paths: ";
    cin>>e;
    cout<<endl;

    depart =new string[v];
    for(int i=0;i<v;i++){
        cout<<"Enter the Name of Department no."<<i+1<<": ";
        cin>>depart[i];
    }

    while(true){
        cout<<"\nEnter the Main Source Department: ";
        string str;
        cin>>str;
        int flag=0;
        for(int i=0;i<v;i++){
            if(toLowerCase(depart[i]).compare(toLowerCase(str))==0){
                temp=i;
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<"\nEnter a Valid Source Department"<<endl;
        }
        else{
            break;
        }
    }

    matrix=new int*[v];
    for(int i=0;i<v;i++){
        matrix[i]=new int[v];
        fill_n(matrix[i],v,INT_MAX);
    }

    cout<<"\nGive Information of Paths between Departments:-"<<endl;
    int s1,s2,dist;
    string str1,str2;
    for(int i=0;i<e;i++){
        cout<<"\nPath no "<<i+1<<": "<<endl;
        while(true){
            int flag1=0;
            cout<<"Enter Source Department: ";
            cin>>str1;
            for(int j=0;j<v;j++){
                if(toLowerCase(depart[j]).compare(toLowerCase(str1))==0){
                    s1=j;
                    flag1=1;
                    break;
                }
            }
            if(flag1==0){
                cout<<"\nEnter a Valid Source Department\n"<<endl;
            }
            else{
                break;
            }
        }
        while(true){
            int flag2=0;
            cout<<"Enter Destination Department: ";
            cin>>str2;
            for(int k=0;k<v;k++){
                if(toLowerCase(depart[k]).compare(toLowerCase(str2))==0){
                    s2=k;
                    flag2=1;
                    break;
                }
            }
            if(flag2==0){
                cout<<"\nEnter a Valid Destination Department\n"<<endl;
            }
            else{
                break;
            }
        }    
        cout<<"Enter the Distance between them: ";
        cin>>dist;
        if(dist<matrix[s1][s2]){
            matrix[s1][s2]=dist;
            matrix[s2][s1]=dist;
        }
    }
};

void Graph::primsAlgo(){
    arr=new int[v];
    fill_n(arr,v,0);
    arr[temp]=1;
    cout<<"\nMinimum Spanning Tree is"<<endl;
    int edge=0,min_span_dist=0;
    while(edge<v-1){
        int min=INT_MAX,x,y;
        for(int i=0;i<v;i++){
            if(arr[i]==1){
                for(int j=0;j<v;j++){
                    if(arr[j]==0){
                        if(matrix[i][j]<min){
                            min=matrix[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
        arr[y]=1;
        edge++;
        cout<<depart[x]<<" - "<<depart[y]<<" = "<<matrix[x][y]<<" units"<<endl;
        min_span_dist=min_span_dist+matrix[x][y];
    }
    cout<<"Minimum Spanning Distance is "<<min_span_dist<<" units"<<endl;
};

string Graph::toLowerCase(string str){
    transform(str.begin(),str.end(),str.begin(),::tolower);
    return str;
};

void Graph::controlGraph(){
    cout<<"This is Demonstration of Prim's Algorithm"<<endl;
    int flag=0;
    createGraph();
    while(flag==0){
        cout<<"\nEnter your choice:\n(1) Apply Prim's Algorithm\n(2) Choose a Different College Campus\n(3) Exit ---> ";
        int choice;
        cin>>choice;
        switch(choice){
            case 1: primsAlgo();
            break;
            case 2: createGraph();
            break;
            case 3: cout<<"\nThank you"<<endl;
            flag=1;
            break;
            default: cout<<"\nEnter a valid choice"<<endl;
        }
    }
};

int main(){
    Graph g;
    g.controlGraph();
}