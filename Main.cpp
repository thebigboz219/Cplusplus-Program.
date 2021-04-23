#include <iostream>
#include <iomanip>
#include "Functions.h"

using namespace std;

int main() {
	double initInv = -1.0;
	double monthlyDep = -1.0;
	double annualInt = -1.0;
	int numYears = -1;
	int numMonths;
	char userInput = 'Y';

	while (userInput != 'N') {

		DisplayMenu();	//Calls menu function
		system("PAUSE");
		DisplayMenuInput(initInv, monthlyDep, annualInt, numYears);	//Calls menu with input
		numMonths = numYears * 12;
		system("PAUSE");
		DisplayNoDeposit(initInv, annualInt, numYears);		//Calls display with no monthly deposit
		DisplayDeposit(initInv, monthlyDep, annualInt, numYears);	//Calls display with monthly deposit
		cout << "Would you like to continue? ('N' to quit)" << endl;	//Checks if user wants to input new info
		cin >> userInput;
	}
}