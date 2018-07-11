/*Darius Hooks*/
#include <iostream>
using namespace std;
int menu();
void prime(int, int);
void divisors(int);
void fib(int, int);
bool isprime(int);
int main()
{
	int low, up, num, loop = 0;
	while(loop < 1)
	{
		switch(menu())
		{
			case 1: cout << "Enter lower and upper limits: ";
					cin >> low >> up;
					cout << endl;
					fib(low, up);
					cout << endl << endl;
					break;
			case 2: cout << "Enter lower and upper limits: ";
					cin >> low >> up;
					cout << endl;
					prime(low, up);
					cout << endl << endl;
					break;
			case 3: cout << "Enter the integer to print its divisors: ";
					cin >> num;
					cout << endl;
					divisors(num);
					cout << endl << endl;
					break;
			case 4: loop++;
					break;
		}
	}
	

	system("pause");
	return 0;
}

int menu()
{
	int choice;
	cout << "Select the type of numbers to print:";
	cout << "\n1. Fibonacci Series" << "\n2. Prime Numbers"
		<< "\n3. Divisors" << "\n4. Quit" << "\n?  ";
	cin >> choice;
	cout << endl;
	while(choice <= 0 || choice > 4)
	{
		cout << "Invalid entry! Enter a number 1-4.";
		cout << "\n1. Fibonacci Series" << "\n2. Prime Numbers"
			<< "\n3. Divisors" << "\n4. Quit" << "\n?  ";
		cin >> choice;
		cout << endl;
	}
	return choice;
}


bool isprime(int n)
{
		for(int i = 2; i < n / 2 + 1; i++)
			if(n % i == 0)
				return false;
		return true;
}


void prime(int l, int u)
{
	for(int i = l; i <= u; i++)
		if(isprime(i))
			cout << i << ' ';
}


void divisors(int n)
{
	int count = 0;
	for(int i = 2; i < n; i++)
		if(n % i == 0)
		{
			count++;
			cout << i << ' ';
		}
	if(count == 0)
		cout << n << " is prime.";
}


void fib(int lw, int uu)
{
	int num1 = lw, num2 = lw + 1, sum = num1 + num2;
	cout << num1 << ' ' << num2 << ' ';
	
	while(sum < uu)
	{
		cout << sum << ' ';
		num1 = num2;
		num2 = sum;
		sum = num1 + num2;
	}

}
