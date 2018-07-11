/*Write a function that takes a character and an integer for its parameters
and prints the character as many times as the integer parameter passed to it.
Write the main program where you read a character and number of times to 
print the character and pass them to the function to print the character
as many times as the integer parameter.*/
/*#include <iostream>
using namespace std;
void print(char, int);
void main()
{
	int num;
	char ch;

	cout << "Enter a character: ";
	cin >> ch;
	cout << endl;
	cout << "Enter parameter: ";
	cin >> num;
	cout << endl;

	print(ch, num);
	cout << endl << endl;
	system("pause");
}

void print(char c, int n)//There's nothing to return so use void
{
	for(int i = 0; i < n; i++)
		cout << c << ' ';
}*/



/*Write a function that takes the lower and upper limits and an integer
and prints as many random numbers as the integer within the range specified
by the lower and upper limits, inclusive.
*/
/*#include <iostream>
#include <ctime>
using namespace std;
void print(int, int, int);
void main()
{
	int low, up, num;
	srand((unsigned)time(0));

	cout << "Enter lower and upper limits: ";
	cin >> low >> up;
	cout << endl;

	cout << "Enter an integer: ";
	cin >> num;
	cout << endl;
	
	for(int i = 0; i < num; i++)
		print(low, up, num);
		cout << endl << endl;
	system("pause");
}

void print(int l, int u, int n)
{
	for(int i = l; i < u; i++) 
		n = l + rand() % u - l + 1;
		cout << n << ' '; 
}*/



/*Write a function that takes the numerator and denominator of two fractions
and computes the sum fraction. Then, it passes the numerator and denominator
of the sum fraction to a reduce function which reduces the sum fraction
and passes the numerator and denominator of the reduced fraction
to a print function which prints the fraction.
*/
/*#include <iostream>
using namespace std;
void sum(int, int, int, int);
void reduce(int, int);
void print(int, int);
void main()
{
	int n1, n2, d1, d2;
	char ch;

	cout << "Enter two fractions: ";
	cin >> n1 >> ch >> d1 >> n2 >> ch >> d2;
	cout << endl;
	sum(n1, d1, n2, d2);
	cout << endl << endl;
	system("pause");
}

void sum(int a, int b, int c, int d)
{
	int nm, dn;
	nm = a * d + c * b;
	dn = d * b;
	reduce(nm, dn);
}

void reduce(int nr, int dr)
{
	for(int i = nr; i >= 1; i--)
		if(nr % i == 0 && dr % i == 0)
		{
			nr /= i;
			dr /= i;
			break;
		}
	print(nr, dr);
}

void print(int nu, int de)
{
	cout << nu << '/' << de;
}*/



/*Write a function that prints the following menu and returns the selected choice:
1. Fibonacci series
2. Prime numbers
3. Divisors
4. Quit
Have main call menu function and then read an integer and depending on the choice returned by menu(), 
call a function to pritn fibonacci series, prime numbers, of divisors from 2 to the specific integer.
*/
#include <iostream>
using namespace std;
int menu();
void fib(int, int);
void prime(int, int);
void divisors(int);
void main()
{
	int low, up, num;
	switch(menu())
	{
		case 1: cout << "Enter upper and lower limits: ";
				cin >> low >> up;
				fib(low, up);
				break;
		case 2: cout << "Enter upper and lower limits: ";
				cin >> low >> up;
				prime(low, up);
				break;
		case 3: cout << "Enter the integer to print its divisors: ";
				cin >> num;
				divisors(num);
				break;
		case 4: break;
	}
	
	cout << endl << endl;
	system("pause");
}

int menu()
{
	int choice;
	cout << "Select the type of numbers to print:";
	cout << "\n1. Fibonacci Series" << "\n2. Prime Numbers"
		<< "\n3. Divisors" << "\n4. Quit" << "\n? ";
	cin >> choice;
	return choice;
}

void fib(int low, int up)
{
	

}

void prime(int low, int up)
{

	cout << "\nThe following are prime numbers:\n";
	for(int i = low; i <= up; i++)
	{
		for(int i = 2; i < n / 2 + 1; i++)
			if(n % i == 0)
				cout << i << ' ';
	}

}

