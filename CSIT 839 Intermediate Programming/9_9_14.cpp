/*#include<iostream>
using namespace std;
int points(char);
int main()
{
	char grade;

	cout << "Enter letter grade: ";
	cin >> grade;

	cout << "\nPoints = " << points(grade) << endl << endl;

	system("pause");
	return 0;
}

int points(char gr)
{
	gr = toupper(gr);
	if (gr == 'A')
		return 4;
	else if (gr == 'B')
		return 3;
	else if (gr == 'C')
		return 2;
	else if (gr == 'D')
		return 1;
	else 
		return 0;
}*/


/*#include<iostream>
using namespace std;
int ascii(char);
int main()
{
	char ch;
	cout << "Enter character : ";
	cin >> ch;

	cout << "\nASCII = " << ascii(ch) << endl;
	system("pause");
	return 0;
}

int ascii(char c)
{
	return (int)c;
}*/

/*Write a function that takes an integer as its parameter and returns true or false
depending on whether its a prime number or not.
*/
/*#include<iostream>
using namespace std;
bool prime(int);
int main()
{
	int num;
	
	cout << "Enter an integer: ";
	cin >> num;

	if (prime(num))
		cout << num << " is a prime number" << endl << endl;
	else
		cout << num << " is not a prime number." << endl << endl;
	system("pause");
	return 0;
}

bool prime(int num)
{
	for (int i = 2; i <= num / 2 + 1; i++)
		if (num % i == 0)
			return false;
	return true;
}*/

/*Write a function that takes an integer as its parameters and returns the number
of divisors for that integer*/
/*#include<iostream>
using namespace std;
int divisors(int);
int main()
{
	int num;
	cout << "Enter an integer: ";
	cin >> num;

	cout << endl << num << " has " << divisors(num) << " divisors." << endl << endl;
	system("pause");
	return 0;
}

int divisors(int num)
{
	int count = 0;
	for (int i = 2; i < num / 2 + 1; i++)
		if (num % i == 0)
			count++;
	return count;
}*/

/*Write a function that takes an integer as its parameters and prints the
divisors for that integer*/
#include<iostream>
using namespace std;
void print(int);
int main()
{
	int num;
	cout << "Enter an integer: ";
	cin >> num;
	cout << endl;
	print(num);
	cout << endl << endl;
	system("pause");
	return 0;
}

void print(int num)
{
	int count = 0;
	for (int i = 2; i < num / 2 + 1; i++)
		if (num % i == 0)
			cout << i << ' ';
}