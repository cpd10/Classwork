/*Darius Hooks*/
#include <iostream>
using namespace std;
int main()
{
	char number[5];
	int num, result;
	cout << "Enter a 4-digit number: ";
	cin >> number;

	cout << "Enter base: ";
	cin >> num;
	
	result = ((number[3] - '0') * 1) + ((number[2] - '0') * num) + ((number[1] - '0') * num * num) + 
		((number[0] - '0') * num * num * num); // - '0' converts back to numeric value from ASCII value

	cout << number << " in base " << num << " = " << result << endl;
	
	system("pause");
	return 0;
}