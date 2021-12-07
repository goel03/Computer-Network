#include<iostream>
#include<ctime>
using namespace std;
int main()
{
 int nf,N;
 int no_tr=0;
 srand(time(NULL));
 cout<<endl<<" ENTER THE NUMBER OF FRAMES-->";
 cin>>nf;
 cout<<endl<<"  ENTER THE WINDOW SIZE--> ";
 cin>>N;

 int i=1;
 while(i<=nf)
 {
     int x=0;
     cout<<" SENDERS END "<<endl;
     for(int j=i;j<i+N && j<=nf;j++)
     {

         cout<<"  SENT FRAME --> "<<j<<endl;
         no_tr++;   //no of tansmission
     }
     for(int j=i;j<i+N && j<=nf;j++)
     {
         int flag = rand()%2;   //1 or 0
         cout<<" RECIEVING END : "<<endl;
         if(!flag)
             {

                 cout<<endl<<"  ACKNOWLEDGMENT FOR FRAME--> "<<j<<endl;
                 x++;
             }
         else

             {

                   cout<<endl<<" FRAME  "<<j<<"  NOT RECIEVED "<<endl;
                   cout<<" TIMES OUT!!"<<endl;
                 cout<<endl<<" RETRANSMITTING WINDOW  "<<endl;
                 break;
             }
     }
     cout<<endl;
     i+=x;
 }
 cout<<" ************   TOTAL NUMBER OF TRANSMISSIONS --> "<<no_tr<<endl;
 return 0;
}

