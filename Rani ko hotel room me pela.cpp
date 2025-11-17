/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <iostream>
#include<string>
using namespace std;

int main() {
	int days;
	char choice;
	string Name,Type;
	cout<<"Enter name: ";
	getline(cin, Name);
	cout<<"Enter room type(standard,delux,suite) : ";
	getline(cin,Type);

	cout<<"Include breakfast? (y/n): ";
	cin>>choice;

	cout<<"Enter the no of days :";
	cin>>days;
	cout<<"Days: "<<days;
	
	cout<<"\n------hotel tariff details-------\n";
	cout<<"customer name :"<<Name;
	cout<<"\nroom type :"<<Type;
	cout<<"\ninclude breakfast:"<<choice;
	cout<<"\nenter no. of days :"<<days;
	
	if(choice=='y') {
		cout<<"yes";
	} else {
		cout<<"no";
	}

	




}