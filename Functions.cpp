#include <iostream>
#include <iomanip>
#include "Functions.h"

using namespace std;

void DisplayMenu() {		//Displays the blank menu format for the user before asking for input
	cout << "***************************************" << endl;
	cout << "************** Data Input *************" << endl;
	cout << "Initial Investment Amount:" << endl;
	cout << "Monthly Deposit:" << endl;
	cout << "Annual Interest:" << endl;
	cout << "Number of Years:" << endl;
}

void DisplayMenuInput(double& t_initInv, double& t_monthlyDep, double& t_annualInt, int& t_numYears) {
	t_initInv = -1;
	t_monthlyDep = -1;
	t_annualInt = -1;
	t_numYears = -1;

	cout << "***************************************" << endl;		//Begins going through variables asking for input
	cout << "************** Data Input *************" << endl;
	cout << "Initial Investment Amount:";
	while (t_initInv < 0) {
		cin >> t_initInv;
		while (!cin) {		//Error checking if character or string were entered
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please enter a positive number." << endl;
			cin >> t_initInv;
		}
	}
	cout << "Monthly Deposit:";
	while (t_monthlyDep < 0) {
		cin >> t_monthlyDep;
		while (!cin) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please enter a positive number." << endl;
			cin >> t_monthlyDep;
		}
	}
	cout << "Annual Interest:";
	while (t_annualInt < 0) {
		cin >> t_annualInt;
		while (!cin) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please enter a positive number." << endl;
			cin >> t_annualInt;
		}
	}
	cout << "Number of Years:";
	while (t_numYears < 0) {
		cin >> t_numYears;
		while (!cin) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please enter a positive number." << endl;
			cin >> t_numYears;
		}
	}
}

void YearBalNoDeposit(double t_initInv, double t_annualInt, int t_numYears) {
	double totalAmount = t_initInv;
	double interestAmount;
	int i;

	for (i = 0; i < t_numYears; ++i) {		//Calculates and prints the total and interest each year
		interestAmount = totalAmount * (t_annualInt / 100);
		totalAmount = totalAmount + interestAmount;
		cout << (i + 1) << "\t\t" << fixed << setprecision(2) << totalAmount << "\t\t\t" << interestAmount << endl;
	}
}

void YearBalDeposit(double t_initInv, double t_monthlyDep, double t_annualInt, int t_numYears) {
	double totalAmount = t_initInv;
	double yearInterest;
	double monthInterest;
	int i;
	int j;

	for (i = 0; i < t_numYears; ++i) {		//Calculates monthly interest on top of yearly total
		yearInterest = 0;
		for (j = 0; j < 12; ++j) {
			monthInterest = (totalAmount + t_monthlyDep) * ((t_annualInt / 100) / 12);
			yearInterest = yearInterest + monthInterest;
			totalAmount = totalAmount + t_monthlyDep + monthInterest;
		}
		cout << (i + 1) << "\t\t" << fixed << setprecision(2) << totalAmount << "\t\t\t" << yearInterest << endl;
	}
}

void DisplayNoDeposit(double t_initInv, double t_annualInt, int t_numYears) {	//Displays and calls the calculation without monthly deposit
	cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
	cout << "===================================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
	cout << "-------------------------------------------------------------------\n";
	YearBalNoDeposit(t_initInv, t_annualInt, t_numYears);
}

void DisplayDeposit(double t_initInv, double t_monthlyDep, double t_annualInt, int t_numYears) {	//Displays and calls the calculation with monthly deposit
	cout << "\nBalance and Interest With Additional Monthly Deposits\n";
	cout << "===================================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
	cout << "-------------------------------------------------------------------\n";
	YearBalDeposit(t_initInv, t_monthlyDep, t_annualInt, t_numYears);
}