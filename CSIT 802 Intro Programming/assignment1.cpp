/* Darius Hooks */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	float bill, tax, tip, total, people, amount, num; // float so decimals will be displayed

	cout << "Enter bill amount: $";
	cin >> bill;
	
	cout << "Enter tax rate in %: ";
	cin >> tax;
	
	cout << "Enter tip in %: ";
	cin >> tip;
	
	total = bill + (bill * (tax/100)) + (bill * (tip/100)); 
	
	cout << "\nTotal inlcluding tax of " << tax << "%" << " and gratuity of " << tip << "% is $" 
		<< fixed << setprecision(2) << total << endl; // Used setprecision to get two places after the decimal.

	cout << "Enter number of people to divide by: ";
	cin >> people;

	amount = total/people;
	cout << "\nAmount for each of " << fixed << setprecision(0) << people << " persons: $" 
		<< fixed << setprecision(2) << amount << endl; // Had to use setprecision twice to seperate the two variables, otherwise they would both display two places after the decimal point or none at all
	
	cout << "Rate the service by selecting one of the following: " << endl;
	cout << "1. Excellent" << endl;
	cout << "2. Above average" << endl;
	cout << "3. Average" << endl;
	cout << "4. Below average" << endl;
	cout << "5. Terrible" << endl;
	
	cout << "Enter your choice: ";
	cin >> num;
	
	system("pause"); // Stops the program until a key is pressed
	
	return 0;
}