#include<iostream>
using namespace std;
#define INFINITY 9999
int main() {

int G[50][50];
   int n=8;
   int startnode=0;
   int t;


  cout<<" ENTER THE NUMBER OF NODES --> ";
    cin>>n;

    char ch[8]={'A','B','C','D','E','F','G','H'};   //vertex name initialize
     // taking input
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)        //for same vertex
            {
                G[i][j]=0;
            }
                cout<<"\n  ENTER THE DISTANCE BETWEEN "<<ch[i]<<" - "<<ch[j]<<" --> ";
                cin>>t;
                G[i][j]=G[j][i]=t;
        }
    }

    cout<<endl<<endl <<" -------------------- GRAPH REPRESENT BY ADJACENCEY MATRIX ------------" <<endl;
      for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {

            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }

   int cost[50][50],distance[50],pred[50];
   int visited[50],count,mindistance,nextnode,i,j;

   for(i=0;i<n;i++)
      for(j=0;j<n;j++)
   if(G[i][j]==0)   //initialize the array   0 means infinity
      cost[i][j]=INFINITY;
   else
      cost[i][j]=G[i][j];

   for(i=0;i<n;i++)
    {
      distance[i]=cost[startnode][i];    //starting node =0    //first row
      pred[i]=startnode;                //set to 0
      visited[i]=0;                    //set array 0
   }

   distance[startnode]=0;    //starting node =0
   visited[startnode]=1;    //visit set 1
   count=1;

   while(count<n-1)      //loop will traverse till 8
    {
      mindistance=INFINITY;                          //set the distance infinite
      for(i=0;i<n;i++)
         if(distance[i]<mindistance&&!visited[i])   //except 1 all are not visited
      {
         mindistance=distance[i];
         nextnode=i;
      }

      visited[nextnode]=1;  //set visit 1

      for(i=0;i<n;i++)
         if(!visited[i])

      if(mindistance+cost[nextnode][i]<distance[i])
      {
         distance[i]=mindistance+cost[nextnode][i];
         pred[i]=nextnode;
      }
      count++;
   }
   for(i=0;i<n;i++)
   if(i!=startnode)
  {
       cout<<endl<<endl;
      cout<<"\nDistance of node"<<i<<"="<<distance[i];
      cout<<"\nPath="<<i;
      j=i;
      do
      {
         j=pred[j];
         cout<<"<-"<<j;
      }while(j!=startnode);
   }
}

