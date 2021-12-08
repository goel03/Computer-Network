QUESTION 1:Stimulate cyclic redundancy check(CRC) error detection algorithm for noisy channel.

#include<iostream>
using namespace std;

class Polynomial{
    int *arr ;                                               //array for storing coefficients
    int size;
    int*n;
    int d;
  int *code_word;
    int a=0;
    int b=0;
    int *temp;
                              //size stores highest exponential degree of polynomial
public:
    Polynomial(){                                            //default constructor
        size = 0;
        arr = {};
    }
 void setSize(){                                           //function for input total number of terms in the polynomial
        int s;
        cout<<"\nEnter the degree of polynomial : ";
        cin>>s;
        cout<<endl<<endl;
  if(s<0){
            cout<<"\n Invalid! number cannot be negative.";
            return;
        }
        else
            size = s;
    }
int getSize(){
        return size;
    }
void store_coeff(){                                             //taking input of coefficient of polynomial
        arr = new int[size];
         n = new int[size];                                   //creating dynamic array
        for(int i=0; i<=size; i++){
            cout<<"Enter the coefficient of x^"<<i<<" : ";
            cin>>arr[i];
            cout<<endl;
        }
    }
    void Polynomial_func(){                                       //shows polynomial function
        int i;
        cout<<"\n Function is F(X) :    ";
        for(i = size; i>0; i--){
            cout<<arr[i]<<"(x^"<<i<<") +";
        }
        if(i==0){
            cout<<arr[i]<<"(x^"<<i<<")";
        }
        cout<<endl<<endl;
    }
void binary_stream(){
 cout<<"\nBinary stream is: ";
       	 for(int i=size;i>=0;i--){
       	 	if (arr[i]==0)
       	 	n[i]=0;
       	 	else
       	 	n[i]=1;
       }
       for(int i=size;i>=0;i--)
       cout<<n[i];

       }
void enter_dataword()
    {
        cout<<endl<<"  ENTER THE SIZE OF DATAWORD : "<<endl;
        cin>>d;
        cout<<endl<<"  ENTER THE DATAWORD ---->";
        for(int i=0; i<d; i++)
            cin>>arr[i];
        cout<<endl<<"    ENTERED DATAWORD IS :";
        for(int i=0; i<d; i++)
            cout<<arr[i];
    }
    void output_dataword()
    {        for(int i=0; i<d; i++)
        {
            n[i]=arr[i];    //dataword store in new array
        }
        for(int i=0; i<size; i++)
        {
            n[i+d]=0;      //adding zero in new dataword array
        }
        cout<<endl<<"   DATAWORD APPEND AFTER ADDING ZERO(degree of polynomial)  :";
        for(int i=0; i<(d+size); i++)
            cout<<n[i];
    }
 void division()
    {
 for(int i=0; i<=size; i++)   //loop will go degree+1 times
        {
            temp[i]=arr[i]^n[i];      //apply xor and store in temp array
            a++;                        // a will be degree+1 time
        }
 while(a<(d+size))     //this loop will continue for more terms of dividend
        {
            if(temp[1]==0)      //if the resultant value after xor second value is 0
            {
for(int i=0; i<size; i++)
                    temp[i]=temp[i+1];     //swapping will occur or we can say left shift
                temp[size]=n[a++];     //new value will come at right side form data word (a++)means degree+1 or next value
                 for(int i=0; i<size; i++)   //again swapping will there
                    temp[i]=temp[i+1];
                temp[size]=n[a++];
            }
       Else    {
                for(int i=0; i<size; i++)   //this will for if temp[1]==1
                    temp[i]=temp[i+1];
                temp[size]=n[a++];
            }
 for(int i=0; i<=size; i++)
            {
                temp[i]=arr[i]^temp[i];    //now xor again
            }
        }
        cout<<endl<<endl;
        cout<<" CRC IS (remainder)---->"<<endl;

        for(int i=1; i<=size; i++)
        {
            cout<<temp[i];     //our remainder will store in temp variable
        }
for(int i=0; i<d; i++)
        {
            code_word[b]=n[i];    //new dataword will store in codeword
            b++;                    //b++ means from next position we will apend crc
        }

        for(int i=1; i<=size; i++)
        {
            code_word[b++]=temp[i];    //crc is store in temp variable
        }
   cout<<endl<<endl<<endl<<"    THE CODEWORD IS ----> ";

        for(int i=0; i<(d+size); i++)
        {
            cout<<code_word[i];   //final resulatant
        }
    }
};
int main(){
    char ch='y';
    while(ch=='y'||ch=='Y'){
    Polynomial p;
    p.setSize();
    p.store_coeff();
    p.Polynomial_func();
    p.binary_stream();
    p.enter_dataword();
    p.output_dataword();
    p.division();
cout<<"\nDo you want to continue  ";
	cin>>ch;
    }

