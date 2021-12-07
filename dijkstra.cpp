#include<iostream>
using namespace std;
#define INFINITY 9999
#define max 8
void dijkstra(int G[max][max],int n,int startnode);
int main() {


   int G[max][max]={{0,2,0,0,0,0,6,0},{2,0,7,0,2,0,0,0},{0,7,0,3,0,3,0,0},{0,0,3,0,0,0,0,2},{0,2,0,0,0,2,1,0},{0,0,3,0,2,0,0,2},{6,0,0,0,1,0,0,4},{0,0,0,2,0,2,4,0}};
   int n=8;
   int u=0;
   dijkstra(G,n,u);
   return 0;
}
void dijkstra(int G[max][max],int n,int startnode)
 {
   int cost[max][max],distance[max],pred[max];
   int visited[max],count,mindistance,nextnode,i,j;

   for(i=0;i<n;i++)
      for(j=0;j<n;j++)
   if(G[i][j]==0)   //initialize the array   0 means infinity
      cost[i][j]=INFINITY;
   else
      cost[i][j]=G[i][j];

   for(i=0;i<n;i++)
    {
      distance[i]=cost[startnode][i];    //starting node =0    //first row
      pred[i]=startnode;   //set to 0
      visited[i]=0;   //set array 0
   }

   distance[startnode]=0;   //starting node =0
   visited[startnode]=1;    //visit set 1
   count=1;

   while(count<n-1)      //loop will traverse till 8
    {
      mindistance=INFINITY;  //set the distance infinte
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

