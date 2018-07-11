/*
Darius Hooks
CSIT 839
Assignment 1
*/
#include<iostream>
using namespace std;
void calc(int, int, char, int, int, int&, int&);
bool reduce(int&, int&);
int main()
{
	int num1, den1, num2, den2, num = 0, den = 0;
	char ch1, ch2, con;
	do{
		cout << "Enter a fraction expression: ";
		cin >> num1 >> ch1 >> den1 >> ch2 >> num2 >> ch1 >> den2;

		calc(num1, den1, ch2, num2, den2, num, den);//Main calling the calc function.
		
		if (reduce(num, den))//Main calling the reduce function.
			cout << num << '/' << den << ".	The result was reduced.";//Returning true.
		else
			cout << num << '/' << den << ".	The result was not reduced.";//Returning false.

		cout << "\n\nMore?[Y/N]: ";
		cin >> con;
		cout << endl;
	} while (con == 'y' || con == 'Y');

	system("pause");
	return 0;

}
// This function does addition, subtraction, multiplication, and division calculations.
// Then assigns the result to two parameters and passes them back to main.
void calc(int n1, int d1, char ch, int n2, int d2, int& n, int& d)
{
	//n and d are the two parameters the resulting fraction will be assigned to.
	//ch designates whether to perform addition, subtraction, multiplication, or division.
	if (ch == '+')
	{
		n = n1*d2 + d1*n2;
		d = d1*d2;
	}

	else if (ch == '-')
	{
		n = n1*d2 - d1*n2;
		d = d1*d2;
	}

	else if (ch == '*')
	{
		n = n1*n2;
		d = d1*d2;
	}

	else if (ch == '/')
	{
		n = n1*d2;
		d = d1*n2;
	}

}

//This function reduces the calculated parameters that were passed back to main.
//Then returns true if reduction was possible and false if it was not.
bool reduce(int& nm, int& dn)
{
	for (int i = nm; i > 1; i--)
		if (nm % i == 0 && dn % i == 0)
		{
		nm = nm / i;
		dn = dn / i;
		return true;
		}
	return false;
}