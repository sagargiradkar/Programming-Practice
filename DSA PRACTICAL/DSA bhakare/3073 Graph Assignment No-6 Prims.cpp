/* Prims Program algorithm for college campus*/
#include <iostream>
using namespace std;
#define ROW 7
#define COL 7
#define true 1 
#define false 0 
#define INF 5000  //INF for INFinity

class Prims{
   int Graph[ROW][COL],nodes;
   public:
   Prims();
   void CreateGraph();
   void PrimsAlgo();
};
Prims :: Prims(){//
    for(int i=0;i<ROW;i++)
       for(int j=0;j<COL;j++)
            Graph[i][j]=0;
}
void Prims :: CreateGraph(){
    int i,j,s,d,w, edg;
    cout<<"Enter Total Number of Nodes : ";
    cin>>nodes;
    for(i=0;i<nodes;i++){
        for(j=0;j<nodes;j++){
            Graph[i][j]=INF;
        }
    }
    cout<<"\n Enter number of edges :";
    cin>>edg;
    cout<<"===============DEPT LOCATIONS================== \n  Node 1=> IT DEPT \n NODE 2=> COMP DEPT \n NODE 3=> ENTC DEPT \n NODE 4=> ELEC DEPT \n NODE 5=> PRINT DEPT \n NODE 6=> MECH DEPT \n NODE 7=> AIDS DEPT \n===========================================================\n";
    
    for(int i=0;i<edg;i++){
        cout<<"Enter source DEPT:";     //Enter DEPT NO as 1,2,3,..
        cin>>s;
        cout<<"Enter destination DEPT:"; //Enter DEPT NO as 1,2,3,.
        cin>>d;
        cout<<"Enter Distance:";
        cin>>w;
        Graph[d-1][s-1]=w;
        Graph[s-1][d-1]=w;
    }
    
}
void Prims :: PrimsAlgo(){
    int selected[ROW],i,j,ne; //ne for no. of edges
    int min,x,y, cost=0;
    string na;
    for(i=0;i<nodes;i++)
       selected[i]=false;
    selected[0]=true;
    ne=0;

    while(ne < nodes-1){
       min=INF;
       for(i=0;i<nodes;i++){
          if(selected[i]==true){
                for(j=0;j<nodes;j++){
                    if(selected[j]==false){
                         if(min > Graph[i][j]){
                            min=Graph[i][j];
                            x=i;
                            y=j;    
                        }
                    }
                }
            }
        }
       selected[y]=true;
       cout<<"\n"<<x+1<<" --> "<<y+1<<"="<<min<<"Km";
       cost=cost+min;
       ne=ne+1;
    }
    cout << "\n Minimum Spanning Tree Distance = "<<cost<<"Km";
}
int main(){
    Prims MST;
        cout<<"\nPrims Algorithm to find Minimum Spanning Tree\n";
        MST.CreateGraph();
        cout<<"===================PVG'S COLLEGE DEPT LOCATIONS================== \n  Node 1=> IT DEPT \n NODE 2=> COMP DEPT \n NODE 3=> ENTC DEPT \n NODE 4=> ELEC DEPT \n NODE 5=> PRINT DEPT \n NODE 6=> MECH DEPT \n NODE 7=> AIDS DEPT \n===========================================================\n";
    
        MST.PrimsAlgo();
        return 0;
}




