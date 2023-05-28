#include<iostream>
#include<limits.h>
#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
//stucture
struct table{
    int dist,pver;
};

class Graph{
    private:
        int v,e,temp;
        int **matrix;
        int *arr;
        struct table *T;
        string *landmark;
    public:
        void createGraph();
        string toLowerCase(string str);
        void dijkstrasAlgo();
        void controlGraph();
};

void Graph::createGraph(){
    cout<<"\nEnter the Information of City:-\n"<<endl;
    cout<<"Enter the number of Landmarks: ";
    cin>>v;
    cout<<"Enter the number of Paths: ";
    cin>>e;
    cout<<endl;

    landmark=new string[v];
    for(int i=0;i<v;i++){
        cout<<"Enter the Name of Landmark no."<<i+1<<": ";
        cin>>landmark[i];
    }

    while(true){
        cout<<"\nEnter the Main Source Landmark: ";
        string str;
        cin>>str;
        int flag=0;
        for(int i=0;i<v;i++){
            if(toLowerCase(landmark[i]).compare(toLowerCase(str))==0){
                temp=i;
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<"\nEnter a Valid Source Landmark"<<endl;
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

    cout<<"\nGive Information of Paths between Landmarks:-"<<endl;
    int s1,s2,dist;
    string str1,str2;
    for(int i=0;i<e;i++){
        cout<<"\nPath no "<<i+1<<": "<<endl;
        while(true){
            int flag1=0;
            cout<<"Enter Source Landmark: ";
            cin>>str1;
            for(int j=0;j<v;j++){
                if(toLowerCase(landmark[j]).compare(toLowerCase(str1))==0){
                    s1=j;
                    flag1=1;
                    break;
                }
            }
            if(flag1==0){
                cout<<"\nEnter a Valid Source Landmark\n"<<endl;
            }
            else{
                break;
            }
        }
        while(true){
            int flag2=0;
            cout<<"Enter Destination Landmark: ";
            cin>>str2;
            for(int k=0;k<v;k++){
                if(toLowerCase(landmark[k]).compare(toLowerCase(str2))==0){
                    s2=k;
                    flag2=1;
                    break;
                }
            }
            if(flag2==0){
                cout<<"\nEnter a Valid Destination Landmark\n"<<endl;
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

void Graph::dijkstrasAlgo(){
    arr=new int[v];
    fill_n(arr,v,0);
    arr[temp]=1;
    
    table t;
    t.dist=INT_MAX;
    t.pver=0;
    T=new table[v];
    fill_n(T,v,t);
    T[temp].dist=0;

    int src=temp, j, Min, Edge_count = 0;
    do
    {
        Min = INT_MAX;
        for (int i=0;i<=v-1;i++)
        {
            if (src != i && matrix[src][i] != Min && arr[i] == 0)
            {
                if (T[i].dist > (T[src].dist + matrix[src][i]))
                {
                     T[i].dist = matrix[src][i]+T[src].dist; 
                     T[i].pver = src;
                }
            }
        }
        Min = INT_MAX;
        for (j = 0; j <= v - 1; j++)
        {
            if (arr[j] == 0 && T[j].dist < Min)
            {
                Min = T[j].dist;
                src = j;
            }
        }
        arr[src] = 1;
        Edge_count = Edge_count + 1;
    } while (Edge_count <= v - 1);

    cout<<"Distance Table:-"<<endl;
    cout<<"Landmark - Distance - Prev. Landmark"<<endl;
    for (int i = 0; i <= v - 1; i++){
        cout<<setfill(' ')<<left<<setw(14)<<landmark[i]<<setfill(' ')<<left<<setw(10)<<T[i].dist<<landmark[T[i].pver]<<endl;
    }
    cout<<"\nSource - Destination - Distance"<<endl;
    for (int i = 0; i <= v - 1; i++){
        cout<<setfill(' ')<<left<<setw(11)<<landmark[temp]<<setfill(' ')<<left<<setw(15)<<landmark[i]<<T[i].dist<<endl;
    }
};

string Graph::toLowerCase(string str){
    transform(str.begin(),str.end(),str.begin(),::tolower);
    return str;
};

void Graph::controlGraph(){
    cout<<"This is Demonstration of Dijkstra's Algorithm"<<endl;
    int flag=0;
    createGraph();
    while(flag==0){
        cout<<"\nEnter your choice:\n(1) Apply Dijkstra's Algorithm\n(2) Choose a Different City Landmarks\n(3) Exit ---> ";
        int choice;
        cin>>choice;
        switch(choice){
            case 1: dijkstrasAlgo();
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