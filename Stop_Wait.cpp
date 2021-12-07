/**STOP AND WAIT */

#include<iostream>
#include<time.h>
using namespace std;

struct packet
{
    int data;
};

struct frame
{
    packet pdata;
    int seq;
};

void network_to_data(int data)
{
    cout<<endl<<" DATA "<<data<<" CONVERTED TO PACKET -->"<<endl;
}

void network_to_dataA(int data)  //for ack
{
    cout<<endl<<" ACKNOWLEDGEMNET "<<data<<" CONVERTED TO PACKET-->"<<endl;
}

void data_to_physicalA(int ack)
{
    cout<<endl<<" PACKET IS CONVERTED TO FRAME (ACK)----->SEQUENCE NUMBER IS--> "<<ack<<endl;
    cout<<endl<<" ACK SEND TO SENDER -->"<<endl;
}

void data_to_physical(frame f1)
{
    packet pack=f1.pdata;
    cout<<endl<<" PACKET IS CONVERTED TO FRAME (DATA)-----> "<<pack.data<<" SEQUENCE NUMBER IS--> "<<f1.seq<<endl;
    cout<<" FRAME SEND TO RECIEVER -->"<<endl;
}

void physical_to_data(frame f)
{
    packet p=f.pdata;
    int no=f.seq;
    cout<<"  FRAME IS RECIEVED FROM PHYSICAL LAYER --->";
    cout<<" INFO-->"<<p.data<<"  SEQUENCE NUMBER --->"<<no<<endl;
}

void data_to_network()
{
    cout<<"Frame is now Converted back to Packet \n";
}

int receiver(frame f,int st)
{
    packet p;
    int  d;
    int s;
    cout<<"\n\n\n         Receiver End:\n\n";

	if(st==5)
        cout<<"   FRAME DISCARDED !!!";
    else
    {
        physical_to_data(f);
        p=f.pdata;
        s=f.seq;
        d=p.data;
        data_to_network();
    }

	if(s==0)
		s=1;
	else
		s=0;

	cout<<"\n ACKNOWLEDGEMENT TRANSMISSION\n"<<endl;
	network_to_dataA(s);
	data_to_physicalA(s);
    return s;
}

int sender(int data,int s,int cases)
{
    int var=-1;  //initial value
    int check;
    packet pack;
    pack.data=data;
    cout<<"\n\n         Sender End:\n\n";
    network_to_data(data);
    frame f1;
    f1.pdata=pack;
    f1.seq=s;
    data_to_physical(f1);

	if(cases==1||cases==2||cases==3)
    {

		cout<<endl<<" ACKNOWLEDGE NOT RECIEVED!!!";
        return var;
    }

    else if (cases==5)
    {
        check=receiver(f1,5);
        cout<<"\n\nSender End:\n\n";

	if(check>1)
            cout<<endl<<"  ACKNOWLEDGE FAILED !!!"<<endl;
        else if(check==0)
            cout<<endl<<" ACK RECIEVED WITH SEQUENCE NUMBER -->"<<check<<endl;
        else
             cout<<endl<<"  ACK RECIEVED WITH SEQUENCE NUMBER -->"<<check<<endl;
    }
    else
    {
        check=receiver(f1,0);
        cout<<"\n\nSender End:\n\n";

		if(check>1)
            cout<<endl<<"  ACKNOWLEDGE FAILED !!!"<<endl;
        else if(check==0)
            cout<<endl<<" ACK RECIEVED WITH SEQUENCE NUMBER -->"<<check<<endl;
        else
             cout<<endl<<"  ACK RECIEVED WITH SEQUENCE NUMBER -->"<<check<<endl;
    return 0;
}
}
int main()
{
    int choice;  //for cases
    int n,i;
    cout<<" ENTER THE NUMBER OF FRAME-->";
    cin>>n;
    int data[n];     //data array

	for(i=0;i<n;i++)
    {
        cout<<" ENTER THE DATA -->"<<i+1<<endl;   //taking input
        cin>>data[i];
    }

	cout<<endl;
    for(i=0;i<n;i++)   //loop will go to n
    {
        int ch;

        choice=rand()%4;    //random number
        switch(choice)
        {
            case 3:
				cout<<" CASE 3-> (WHEN ACKNOWLEDGEMENT IS LOST :)"<<endl;

				ch=sender(data[i],(i+1)%2,choice);
				if(ch==-1)
				{
					cout<<"\n**Frame is Sent Again....**\n ";
					ch=sender(data[i],(i+1)%2,5);
				}
				break;
            case 2:
				cout<<" CASE 2 --> WHEN FRAME IS LOST :"<<endl;

				ch=sender(data[i],(i+1)%2,choice);
				if(ch==-1)
				{
					cout<<"\n**Frame is Sent Again....**\n ";
					ch=sender(data[i],(i+1)%2,0);
				}
				break;
            case 1:
				cout<<" CASE 1 --> WHEN FRAME GETS DAMAGE :"<<endl;
				ch=sender(data[i],(i+1)%2,choice);
				if(ch==-1)
				{
					cout<<"\n**Frame is Sent Again....**\n ";
					ch=sender(data[i],(i+1)%2,0);
				}
				break;
            default:
				cout<<" DEFAULT CASE --> NORMAL FRAME :"<<endl;
				ch=sender(data[i],(i+1)%2,choice);
				break;
        }
    }
    cout<<" ************************************ STOP AND WAITS COMPLETE *********************************** ";
    return 0;
}

