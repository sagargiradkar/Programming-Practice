#include<iostream>
using namespace std;
struct table{
    // int ver;
    int dist;
    int pver;
};
class G{
    int v,e,visit[20],graph[20][20];
    string cities[6]={"Pune","Nagar","Magarpatta","Hadapsar","Chakan","Swargate"};
    struct table T[20];
    public:
    void Info_city();
    void Matrix_read_graph();
    void Find_short_Path();
};
void G::Info_city(){
    int i,j;
    cout<<"Input no of Cities=";
    cin>>v;
    cout<<"Input no of Routes=";
    cin>>e;
    for(i=0;i<v;i++)
        visit[i]=0;
    for(i=0;i<v;i++)
        for(j=0;j<v;j++)
            graph[i][j]=9999;

    for(i=0;i<v;i++){
        T[i].dist =9999;
        T[i].pver = 0;
    }
}
void G::Matrix_read_graph(){
        int i,j,s,d,w;
        for(int i=0;i<e;i++){
            cout<<"========================================"<<endl;
            cout<<"Enter First_city---->dest_city =Distance"<<endl; // input s,d as 1,2,3...not 0
            cin>>s;
            cout<<"---->";
            cin>>d;
            cout<<"=";
            cin>>w;

            graph[d-1][s-1]=w;
            graph[s-1][d-1]=w;
        }
        cout<<"==============ADJACENCY MATRIX================="<<endl;
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                cout<<"     "<<graph[i][j]<<"         ";
            }
            cout<<endl;
        }
        cout<<"==============================================="<<endl;
}
//1 2 7, 1 3 2, 2 3 6, 3 4 4, 2 5 5, 4 5 2
//1 2 6, 1 4 1, 2 4 2, 4 5 1, 2 5 2, 2 3 5, 3 5 5
void G::Find_short_Path(){
    int src,i,j,Min,Edge_count=0;
    int S;
    char ch;
    cout<<"Enter First City To Start:";
    cin>>src;
    S=src;
    src=src-1;
    visit[src] = 1;
    T[src].dist =0;
    T[src].pver = 0;
    do{
        Min =9999;
        for(i=0;i<v;i++){
            if (src!=i && graph[src][i]!=Min && visit[i] ==0){
                if (T[i].dist>(T[src].dist+ graph[src][i])){
                    T[i].dist =T[src].dist+ graph[src][i];
                    T[i].pver =src;
                }
            }
        }
        Min = 9999;
        for (j=0;j<v;j++)
        {
            if(visit[j] ==0 && T[j].dist<Min){
                Min = T[j].dist;
                src = j;
            }
        }
        visit[src]=1;
        Edge_count = Edge_count+1;
    }while(Edge_count<v);
    cout<<endl<<"=========================Distance Table======================"<<endl;
    cout<<"vertex"<<"    "<<"Distance" <<"    "<<"previous vertex"<<endl;
    for(i=0;i<v;i++){
        cout<<i+1<<"            "<<T[i].dist<<"            "<<T[i].pver<<endl;
    }
    cout<<"===============CITIES REFERENCE===================="<<endl;
    for(int i=0;i<v;i++){
        cout<<"Node:"<<i+1<<":"<<cities[i]<<endl;
    }
    cout<<"==================================================="<<endl;
    cout<<endl<<"Source---------->destination  =  Distance"<<endl;
    for(i=0;i<v;i++){
        //cout<<S<<"------------>"<<i+1<<"="<<T[i].dist<<endl;
        cout<<cities[S-1]<<"------------>"<<cities[i]<<" = "<<T[i].dist<<"Km"<<endl;
    }
}
int main(){
    G shortd;
    int choice;
    while(true){
        cout<<"====================FIND SHORTEST PATH======================"<<endl;
        cout<<"1]Take Information of required graph \n2]Enter source & Destination cities and distance \n3]Show Shortest path \n4]Exit \nEnter your choice:";
        cin>>choice;
        switch(choice){
            case 1:
                shortd.Info_city();//Method to take input from user.
                break;
            case 2:
                shortd.Matrix_read_graph();
                break;
            case 3:
                shortd.Find_short_Path();
                break;
            case 4:
                break;
            default:cout<<"Enter the valid choice:";
        }
        if(choice==4){
            cout<<"====================THANK YOU==============================="<<endl;
            break;
        }
    }    
    return 0;
}
/*======================================OUTPUT===============================
====================FIND SHORTEST PATH======================
1]Take Information of required graph
2]Enter source & Destination cities and distance
3]Show Shortest path
4]Exit
Enter your choice:1
Input no of Cities=5
Input no of Routes=7
====================FIND SHORTEST PATH======================
1]Take Information of required graph
2]Enter source & Destination cities and distance
3]Show Shortest path
4]Exit
Enter your choice:2
========================================
Enter First_city---->dest_city =Distance
1
---->2
=10
========================================
Enter First_city---->dest_city =Distance
1
---->4
=30
========================================
Enter First_city---->dest_city =Distance
1
---->5
=100
========================================
Enter First_city---->dest_city =Distance
2
---->3
=50
========================================
Enter First_city---->dest_city =Distance
3
---->5
=10
========================================
Enter First_city---->dest_city =Distance
3
---->4
=20
========================================
Enter First_city---->dest_city =Distance
4
---->5
=60
==============ADJACENCY MATRIX=================
     9999              10              9999              30              100
     10              9999              50              9999              9999
     9999              50              9999              20              10
     30              9999              20              9999              60
     100              9999              10              60              9999
===============================================
====================FIND SHORTEST PATH======================
1]Take Information of required graph
2]Enter source & Destination cities and distance
3]Show Shortest path
4]Exit
Enter your choice:3
Enter First City To Start:1

=========================Distance Table======================
vertex    Distance    previous vertex
1            0            0
2            10            0
3            50            3
4            30            0
5            60            2
===============CITIES REFERENCE====================
Node:1:Pune
Node:2:Nagar
Node:3:Magarpatta
Node:4:Hadapsar
Node:5:Chakan
===================================================

Source---------->destination  =  Distance
Pune------------>Pune = 0Km
Pune------------>Nagar = 10Km
Pune------------>Magarpatta = 50Km
Pune------------>Hadapsar = 30Km
Pune------------>Chakan = 60Km
====================FIND SHORTEST PATH======================
1]Take Information of required graph
2]Enter source & Destination cities and distance
3]Show Shortest path
4]Exit
Enter your choice:4
====================THANK YOU=============================== */