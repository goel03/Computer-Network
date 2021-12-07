

#include<iostream>
#include<cstdlib>
using namespace std ;

class CheckSum{
	private :
		int size_dw ;
		int size_cs ;
		int remainder ;
		int* dataword ;
		int* checksum ;
		int* codeword ;
	public :
		CheckSum() ;
		~CheckSum() {} ;

		void chInput() ;
		void dec_Add() ;
		void complement() ;
		void append() ;
		void Sender() ;
		void receiver() ;
		void createRnError() ;
};

CheckSum :: CheckSum() {
	size_dw = 0 ;
	size_cs = 8 ;
	dataword = 0 ;
	remainder = 0 ;
	checksum = 0 ;
}

void CheckSum :: chInput() {

	cout << " ENTER THE LENGTH OF CHECKSUM-->  " ;
	cin >> size_cs ;

	checksum = new int[size_cs] ;


	cout << " ENTER THE SIZE OF DATAWORD IN BITS-->    " ;
	cin >> size_dw ;

	if(size_cs > size_dw)
		remainder = size_cs % size_dw ;
	else {
		remainder = size_dw % size_cs ;
		if(remainder != 0)
			remainder = size_cs - remainder ;
	}

	dataword = new int[size_dw + remainder] ;
	codeword = new int[size_dw + remainder + size_cs] ;

	cout<<endl<<" ENTER DATAWORD -->"<<endl;

	for(int i=size_dw - 1 ; i>=0 ; i--) {

		cin >> dataword[i] ;
	}

	for(int i=size_dw + remainder - 1 ; i>= size_dw ; i--)
		dataword[i] = 0 ;

	return ;
}

void CheckSum :: dec_Add() {
	int quo = (size_dw + remainder) / size_cs ;

	int** temp = new int*[quo] ;

	for(int i=0 ; i<quo ; i++)
		temp[i] = new int[size_cs] ;

	int count = size_dw + remainder - 1 ;

	for(int i=0 ; i<quo ; i++)
		for(int j=size_cs - 1 ; j>=0 ; j--) {
			temp[i][j] = dataword[count--] ;
		}

	int carry = 0 , sum = 0 ;

	for(int i=1 ; i<quo ; i++) {
		for(int j=0 ; j<size_cs ; j++) {
			for(int k=0 ; k<quo ; k++) {
				sum = temp[k][j] + sum ;
			}
			sum = sum + carry ;

			if(sum%2 == 0)
				checksum[j] = 0 ;
			else
				checksum[j] = 1 ;

			carry = sum/2 ;
			sum = 0 ;
		}
	}

	count = 0 ;

	while(carry != 0) {
		sum = checksum[count] + carry ;

		if(sum%2 == 0)
			checksum[count++] = 0 ;
		else
			checksum[count++] = 1 ;

		carry = sum/2 ;
		sum = 0 ;
	}

	return ;
}

void CheckSum :: complement() {
	for(int i=0 ; i<size_cs ; i++) {
		if(checksum[i] == 1)
			checksum[i] = 0 ;
		else
			checksum[i] = 1 ;
	}

	cout << "\nChecksum :   " ;

	for(int i=size_cs - 1 ; i>=0 ; i--)
		cout << checksum[i] ;

	return ;
}

void CheckSum :: append() {
	int count = size_dw + remainder - 1 ;

	for(int i = size_dw + remainder + size_cs - 1 ; i>=size_cs ; i--) {
		codeword[i] = dataword[count--] ;
	}

	for(int i = size_cs - 1 ; i>=0 ; i--)
		codeword[i] = checksum[i] ;

	cout << "\n\nCodeword :   " ;

	for(int i = size_dw + remainder + size_cs - 1 ; i>=0 ; i--)
		cout << codeword[i] ;


    cout<<endl;
	return ;
}

void CheckSum :: Sender() {
	chInput() ;
	cout<<endl<<endl;
	dec_Add() ;
	cout<<endl;

	complement() ;
	cout<<endl;
	append() ;

	return ;
}

void CheckSum :: receiver() {
	int quo = (size_dw + remainder + size_cs) / size_cs ;
	bool flag = true ;

	int** temp = new int*[quo] ;

	for(int i=0 ; i<quo ; i++)
		temp[i] = new int[size_cs] ;

	int count = size_dw + remainder + size_cs - 1 ;

	for(int i=0 ; i<quo ; i++)
		for(int j=size_cs - 1 ; j>=0 ; j--) {
			temp[i][j] = codeword[count--] ;
		}

	int carry = 0 , sum = 0 ;

	for(int i=1 ; i<quo ; i++) {
		for(int j=0 ; j<size_cs ; j++) {
			for(int k=0 ; k<quo ; k++) {
				sum = temp[k][j] + sum ;
			}
			sum = sum + carry ;

			if(sum%2 == 0)
				checksum[j] = 0 ;
			else
				checksum[j] = 1 ;

			carry = sum/2 ;
			sum = 0 ;
		}
	}

	count = 0 ;

	while(carry != 0) {
		sum = checksum[count] + carry ;

		if(sum%2 == 0)
			checksum[count++] = 0 ;
		else
			checksum[count++] = 1 ;

		carry = sum/2 ;
		sum = 0 ;
	}

	for(int i=0 ; i<size_cs ; i++) {
		if(checksum[i] == 1)
			checksum[i] = 0 ;
		else
			checksum[i] = 1 ;
	}

	if(flag == true) {
		cout <<endl<<endl<<" NO ERROR!!!" ;
		cout << " Dataword is :   " ;

		for(int i=size_dw - 1 ; i>=0 ; i--)
			cout << dataword[i] ;
	}else {
		cout << " ERROR!!! " ;
		cout << "\n\nReceived Codeword is :    " ;
		for(int i=size_cs + size_dw + remainder - 1 ; i>=0 ; i--)
			cout << codeword[i] ;
	}


	return ;
}

void CheckSum :: createRnError() {
	int random = (rand() % 2*(size_dw + size_cs + remainder)) ;

	if(random < (size_dw + size_cs + remainder)) {
		if(codeword[random] == 1)
			codeword[random] = 0 ;
		else
			codeword[random] = 1 ;
	}

	return ;
}

int main() {
	CheckSum ob ;
	ob.Sender() ;
	ob.createRnError() ;
	ob.receiver() ;
}

