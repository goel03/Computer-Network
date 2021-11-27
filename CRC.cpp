#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
int deg;
cout<<"Enter the degree of polynomial: ";
cin>>deg;
int b=deg;
int p[deg+1];
cout<<"\nEnter polynomial:\n";
for(int i=0;i<=deg;i++)
{
cout<<"Enter the coefficient of degree "<<b<<": ";
cin>>p[i];
if(p[i]!=0)
p[i]=1;
b--;
}

int len;
cout<<"\nEnter the length of dataword: ";
cin>>len;
int data[len];
cout<<"Enter the dataword: ";
for(int i=0;i<len;i++)
cin>>data[i];
int dw[len+deg];
for(int i=0;i<len;i++)
dw[i]=data[i];
for(int j=len;j<(len+deg);j++)
dw[j]=0;

cout<<"\nDIVIDEND: ";
for(int i=0;i<deg+1;i++)
   cout<<p[i];
cout<<"\nDIVISOR: ";
for(int i=0;i<len+deg;i++)
   cout<<dw[i];

int x=deg+1;
int y=deg+1;
int temp[x];

for(int i=0;i<x;i++)
temp[i]=dw[i];

for(int i=0;i<len;i++)
{
if(temp[0]==1)
{
for(int j=0;j<x;j++)
temp[j]=(temp[j]^p[j]);
}
for(int l=0;l<x;l++)
{
if(l==deg)
temp[l]=dw[y++];
else
temp[l]=temp[l+1];
}
}

cout<<"\n\nCRC BIT= ";
int crc[deg];
for(int i=0;i<deg;i++)
{
   crc[i]=temp[i];
   cout<<crc[i];
}

int code[len+deg];
cout<<"\nCODE WORD SENT= ";
for(int i=0,j=0;i<(len+deg);i++)
{
   if(i<len)
       code[i]=data[i];
   else
       code[i]=crc[j++];
   cout<<code[i];
}

cout<<"\nCODE WORD RECEIVED= ";

int r =rand();
cout<<r;
int rand_no=r%(len+deg);
cout<<endl<<endl<<endl<<" randomnumber is"<<rand_no;
if(code[rand_no]==0)
   code[rand_no]=1;
else
   code[rand_no]=0;
for(int i=0;i<len+deg;i++)
{
   cout<<code[i];
}

int temp2[x];
int k=x;
for(int i=0;i<x;i++)
temp2[i]=code[i];

for(int i=0;i<len;i++)
{
if(temp2[0]==1)
{
for(int j=0;j<x;j++)
temp2[j]=(temp2[j]^p[j]);
}
for(int l=0;l<x;l++)
{
if(l==deg)
temp2[l]=code[k++];
else
temp2[l]=temp2[l+1];
}
}

int rem[deg];
for(int i=0;i<deg;i++)
{
   rem[i]=temp2[i];
}
int ctr=0;
for(int j=0;j<deg;j++)
{
if(rem[j]==0)
ctr++;
}
if(ctr==deg)
cout<<"\nNO ERROR in the received code";
else
cout<<"\nERROR in the received code";
return 1;
}
