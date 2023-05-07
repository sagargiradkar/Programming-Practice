//Prims Program

#include <iostream>
using namespace std;
#define ROW 7
#define COL 7
#define true 1 
#define false 0 
#define infi 5000  //infi for infinity

class prims
{
    int graph[ROW][COL],nodes;
    public:
    prims();
    void createGraph();
    void primsAlgo();
};
prims :: prims(){
    for(int i=0;i<ROW;i++)
        for(int j=0;j<COL;j++)
            graph[i][j]=0;
}
void prims :: createGraph(){
    int i,j,s,d,w, edg;
    cout<<"Enter Total Nodes : ";
    cin>>nodes;
    
    
    for(i=0;i<nodes;i++){
        for(j=0;j<nodes;j++){
            graph[i][j]=infi;
        }
    }
    cout<<"\n Enter number of edges :";
    cin>>edg;
    
    for(int i=0;i<edg;i++)
    {
        cout<<"Enter source :";     //Enter vertex as 1,2,3,..
        cin>>s;
        cout<<"Enter destination :"; //Enter vertex as 1,2,3,.
        cin>>d;
        cout<<"Enter weight :";
        cin>>w;

        graph[d-1][s-1]=w;
        graph[s-1][d-1]=w;
    }
    
}
void prims :: primsAlgo(){
    int selected[ROW],i,j,ne; //ne for no. of edges
    int min,x,y, cost=0;
    
    for(i=0;i<nodes;i++)
    selected[i]=false;
    selected[0]=true;
    ne=0;

    while(ne < nodes-1){
    min=infi;
    for(i=0;i<nodes;i++)
    {
        if(selected[i]==true){
        for(j=0;j<nodes;j++){
            if(selected[j]==false){
            if(min > graph[i][j])
            {
            min = graph[i][j];
                x=i;
                y=j;
            }
            }
        }
        }

    }
    selected[y]=true;
    cout<<"\n"<<x+1<<" --> "<<y+1<<"--"<<min;
    cost=cost+min;
    ne=ne+1;
    }
    cout << "\n cost = "<<cost;
    cout<<endl;
}

int main(){
    prims MST;
    cout<<"\nPrims Algorithm to find Minimum Spanning Tree\n";
    MST.createGraph();
    MST.primsAlgo();
    return 0;
}




