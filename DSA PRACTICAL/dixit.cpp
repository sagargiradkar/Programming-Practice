#include <iostream>
using namespace std;

struct table
{
  int dist;
  int pver;
};

class G
{
    int v,e,visit[20],graph[20][20];
    struct table T[20];
    public:
    void Init();
    void read_G();
    void DIJK();
};

void G::Init()
{
    int i,j;
    cout<<"Enter Total Number of Vertex :";
    cin>>v;
    cout<<"Enter Total Number Of Edges ";
    cin>>e;
    for(i=0;i<v;i++)
       visit[i]=0;
     for(i=0;i<v;i++)
       for(j=0;j<v;j++)
             graph[i][j]=9999;
             
     for(i=0;i<v;i++)
       {
           T[i].dist =9999;
           T[i].pver = 0;
       }            
}

void G::read_G()
{
    int i,j,s,d,w;
    for(int i=0;i<e;i++)
    {
	cout<<"Enter Source Vertex :";
        cin>>s;
	cout<<"Enter Destination Vertex :";
        cin>>d;
	cout<<"Enter Weight of Edge :";
        cin>>w;
        
        graph[d-1][s-1]=w;
        graph[s-1][d-1]=w;
    
}
}

void G::DIJK()
{
    int src,i,j,Min,Edge_count=0;
    int S;
    char ch;
    cout<<"Enter Sorce Vertex :";
    cin>>src;
    S=src;
    src=src-1;
    visit[src] = 1;
    T[src].dist =0;
    T[src].pver = 0;  
    do
    {
    Min =9999;
   for(i=0;i<= v-1;i++)
   {
    if (src!=i &&graph[src][i]!=Min && visit[i] ==0) 
    {
        
     if (T[i].dist> (T[src].dist+ graph[src][i])) 
     {
            T[i].dist = T[src].dist+ graph[src][i];
             T[i].pver = src;
     }        
    }
   }
 
Min = 9999;
for (j=0;j<= v-1;j++)
  {
   if(visit[j] ==0 && T[j]. dist < Min)
    {
             Min =  T[j].dist;
             src = j;  
        }
      }
      visit[src]=1;
    Edge_count = Edge_count+1;  

}while(Edge_count<= v-1);

cout<<endl<<"=====Distance Table ======"<<endl;
cout<<"vertex  "<<"Distance  "<<"previous vertex"<<endl;
   for(i=0;i<= v-1;i++)
   {
       cout<<i+1<<"           "<<T[i].dist<<"            "<<T[i].pver+1<<endl;
   }
   cout<<"================================"<<endl;
  cout<<endl<<"Source->Destination->Distance"<<endl;
  for(i=0;i<= v-1;i++)
   {
       cout<<" "<< S<<"             "<<i+1<<"            "<<T[i].dist<<endl;
   } 
}

int main()
{
    G shortd;
    shortd.Init();
    shortd.read_G();
   shortd.DIJK();
    return 0;
}



    
