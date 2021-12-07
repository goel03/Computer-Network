/** only for one digit */

#include<iostream>
using namespace std;
class CRC
{
private:

    int degree;
    int poly[50];
    int bin[50];
    int dw[50];
    int ndw[50];
    int temp[50];
    int code_word[50];
    int cd[50];

    int a=0;
    int b=0;
    int s;
    int ndw1[50] ;
public:

    void enter()               //enter the polynomial
    {
        cout<<" ENTER THE DEGREE OF THE POLYNOMIAL : " <<endl;
        cin>> degree;

        for(int i=0; i<=degree ; i++)
        {
            cout<<" ENTER THE COEFFICIENT OF THE POLYNOMIAL x^"<<(degree-i)<<"----> " ;
            cin>>poly[i];

        }
    }

    void display()
    {
        cout<<" THE ENTERED POLYNOMIAL IS  ---->";     //diplay the polynomial
        for(int i=degree; i>=0; i--)
        {
            if(i==0)
                cout<<poly[degree-i];
            else
                cout<<poly[degree-i]<<"x^"<<i<<"+";
        }


        cout<<endl<<endl<<endl;
    }



    void bin_pol()     //display polynomial in binary form
    {

        for(int i=0; i<=degree; i++)
        {
            if(poly[i]>0)
            {
                bin[i]=1;
            }
            else
                bin[i]=0;
        }
        cout<<endl<<" POLYNOMIAL IN BINARY STREAM  (DIVISOR)---->";
        for(int i=0; i<degree+1; i++)              //loop will for n+1
        {
            cout<<bin[i];
        }

    }


    void enter_dataword()    //enter the dataword
    {

        cout<<endl<<" ENTER THE SIZE OF DATAWORD : "<<endl;
        cin>>s;
        cout<<endl<<" ENTER THE DATAWORD ---->"<<endl;
        for(int i=0; i<s; i++)
            cin>>dw[i];


        cout<<endl<<" ENTERED DATAWORD IS ---->";
        for(int i=0; i<s; i++)
            cout<<dw[i];
    }



    void output_dataword()    //show the final data word after appending
    {

        for(int i=0; i<s; i++)
        {
            ndw[i]=dw[i];    //data word store in new array
        }
        for(int i=0; i<degree; i++)
        {
            ndw[i+s]=0;      //adding zero in new data word array
        }
        cout<<endl<<endl<<" DATAWORD APPEND AFTER ADDING ZERO(degree of polynomial) ---->";
        for(int i=0; i<(s+degree); i++)
            cout<<ndw[i];
    }



    void division()    //division function
    {

        for(int i=0; i<=degree; i++)   //loop will go degree+1 times
        {
            temp[i]=bin[i]^ndw[i];      //apply xor and store in temp array
            a++;                        // a will be degree+1 time
        }


        while(a<(s+degree))     //this loop will continue for more terms of dividend
        {
            if(temp[1]==0)      //if the resultant value after xor second value is 0


            {

                for(int i=0; i<degree; i++)
                    temp[i]=temp[i+1];     //swapping will occur or we can say left shift
                temp[degree]=ndw[a++];     //new value will come at right side form data word (a++)means degree+1 or next value
                for(int i=0; i<degree; i++)   //again swapping will there
                    temp[i]=temp[i+1];
                temp[degree]=ndw[a++];


            }


            else

            {
                for(int i=0; i<degree; i++)   //this will for if temp[1]==1
                    temp[i]=temp[i+1];
                temp[degree]=ndw[a++];
            }

            for(int i=0; i<=degree; i++)
            {
                temp[i]=bin[i]^temp[i];    //now xor again
            }
        }


        cout<<endl<<endl;
        cout<<" CRC OR (remainder) IS ---->";

        for(int i=1; i<=degree; i++)
        {
            cout<<temp[i];     //our remainder will store in temp variable
        }



        for(int i=0; i<s; i++)
        {
            code_word[b]=ndw[i];    //new dataword will store in codeword
            b++;                    //b++ means from next position we will apend crc
        }

        for(int i=1; i<=degree; i++)
        {
            code_word[b++]=temp[i];    //crc is store in temp variable
        }



        cout<<endl<<endl<<endl<<" THE CODEWORD  (DATAWORD+ CRC) IS ----> ";

        for(int i=0; i<(s+degree); i++)
        {
            cout<<code_word[i];   //final resulatant
        }
    }



void recived_random_no()   //taking random number as a codeword
{
     cout<<endl<<endl;
  cout<<" RANDOM NUMBER GENERATES WHICH IS RECEIVED CODEWORD IS --->";

   for(int i=0; i<(s+degree); i++)      //whole random number
        {

            ndw1[i]=rand()%2;
            cout<<ndw1[i];

        }

}






void received_random_digit()    //only single digit
{

    // ndw1[50] = {0};
    int index=0;
    int digit=0;


    int r =rand();


 for(int i=0; i<s+degree; i++)
            {
                cd[i]= code_word[i];   //real  ,cd after change

            }


    cout<<endl<<endl<<"RANDOM number----->"<<r<<endl;
      index =r%(s+degree);
    cout<<"(RANDOM INDEX GETS CHANGED)----->"<<index<<endl;




digit =r%2;   //0 and 1
    cout<<"Random number generates either 0 or 1 --->"<<digit<<endl;





    cd[index]=digit;

    cout<<endl<<"RECEIVER GET CODEWORD IS ----->";
    for(int i=0;i<s+degree;i++)
    {

        cout<<cd[i];
    }

     for(int i=0;i<s+degree;i++)
    {

       ndw1[i] =cd[i];
    }

}




    void recived()   //manually

    {
        cout<<"  ENTER THE RECIEVED CODEWORD   " <<endl;    //manually print


         for(int i=0; i<(s+degree); i++)
        {
            cin>>ndw1[i];
        }

        cout<<" NEW CODEWORD IS --->";

         for(int i=0; i<(s+degree); i++)
        {
            cout<<ndw1[i];
        }


    }










    void division2()
    {

        int a=0;
        int b=0;
// int ndw1[50] ;

        for(int i=0; i<=degree; i++)   //loop will go degree+1 times
        {
            temp[i]=bin[i]^ndw1[i];      //apply xor and store in temp array
            a++;                        // a will be degree+1 time
        }


        while(a<(s+degree))     //this loop will continue for more terms of dividend
        {
            if(temp[1]==0)      //if the resultant value after xor second value is 0


            {

                for(int i=0; i<degree; i++)
                    temp[i]=temp[i+1];     //swapping will occur or we can say left shift
                temp[degree]=ndw1[a++];     //new value will come at right side form data word (a++)means degree+1 or next value
                for(int i=0; i<degree; i++)   //again swapping will there
                    temp[i]=temp[i+1];
                temp[degree]=ndw1[a++];


            }


            else

            {
                for(int i=0; i<degree; i++)   //this will for if temp[1]==1
                    temp[i]=temp[i+1];
                temp[degree]=ndw1[a++];
            }

            for(int i=0; i<=degree; i++)
            {
                temp[i]=bin[i]^temp[i];    //now xor again
            }

     }







        cout<<endl<<endl;
        cout<<" CRC IS (remainder)---->"<<endl;

        for(int i=1; i<=degree; i++)
        {
            cout<<temp[i];     //our remainder will store in temp variable
        }


          int flag=1;
                 for(int i=0; i<=degree; i++)
    {
        if(temp[i]!=0)
            {

                flag=0;
                break;
            }
        }

        if(flag==0)
        cout<<endl<<" ******************THERE IS ERROR IN RECEIVED CODEWORD************************ "<<endl;
            else
                cout<<endl<<" ***************************THERE IS NO ERRON IN RECEIVED CODEWORD *********************** "<<endl;
        }




};
int main()
{
     int choice;
    char ch='y';



    CRC c;
    c.enter();
    c.display();
    c.bin_pol();
    c.enter_dataword();
    c.output_dataword();
    c.division();
 while(ch=='y'||ch=='Y')
    {

    cout<<endl<<endl<<endl<<" ***************CHOICES FOR RECEIVED NUMBER*********************** "<<endl<<endl;
    cout<< "  1. ENTER THE RECEIVED CODEWORD  MANUALLY "<<endl;
    cout<< "  2. RECIVED CODEWORD BY RANDOM METHOD (CHANGE ONLY ONE DIGIT) "<<endl;
    cout<< "  3. RECIVED CODEWORD BY RANDOM METHOD "<<endl;
    cin>>choice;
    switch(choice)
    {

case 1:

 c.recived();
 break;
case 2:
    c.received_random_digit();
    break;
case 3:

 c.recived_random_no();
 break;

    }
    c.division2();
    cout<<endl<<" ENTER Y/y IF YOU WANT TO CONTINUE YOUR PROGRAM "<<endl;
    cin>>ch;
    }
}
