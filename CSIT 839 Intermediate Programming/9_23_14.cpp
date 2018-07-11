/*#include <conio.h>
cout << "Press any key to continue...";
_getch();*/


/*Write a function that takes two integers and a print function that prints all prime numbers within the range given
by the two integers, using another function that determines if a given integer passed to it as
a parameter is a prime number or not.
Example:
Enter a range: 15 30
17 19 23 29
Press any key to continue...*/
/*#include <iostream>
void print(int, int);
bool prime(int);
using namespace std;
int main()
{
	int num1, num2;
	cout << "Enter a range: ";
	cin >> num1 >> num2;
	cout << endl;

	print(num1, num2);
	cout << endl << endl;

	system("pause");
	return 0;
}

void print(int n1, int n2)
{
	for (int i = n1; i < n2; i++)
		if (prime(i))
			cout << i << ' ';
	
}

bool prime(int i)
{
	for (int j = 2; j < i / 2 + 1; j++)
		if (i % j == 0)
			return false;
	return true;
}*/


/*Write a function that takes two integers and a print function that prints all prime numbers within the range given
by the two integers, using another function that determines if a given integer passed to it as
a parameter is a prime number or not.
Have main print the first and last prime number.
Example:
Enter a range: 15 30
17 19 23 29
17 19
Press any key to continue...*/
/*#include <iostream>
void print(int, int, int&, int&);
bool prime(int);
using namespace std;
int main()
{
int num1, num2, num3 = 0, num4 = 0;
cout << "Enter a range: ";
cin >> num1 >> num2;

print(num1, num2, num3, num4);
if (num3 == 0 && num4 == 0)
	cout << "There are no prime numbers." << endl << endl;
else
	cout << "\n\nFirst: " << num3 << "	Last: " << num4 << endl << endl;
system("pause");
return 0;
}

void print(int n1, int n2, int& n3, int& n4)
{
	int tmp = 0, count = 0;
	cout << endl;
	for (int i = n1; i < n2; i++)
	{
		if (prime(i))
		{
			cout << i << ' ';
			tmp = i;
			count++;
			if (count <= 1)
				n3 = tmp;
		}
		n4 = tmp;
	}
			

}

bool prime(int i)
{
	for (int j = 2; j < i / 2 + 1; j++)
		if (i % j == 0)
			return false;
	return true;
}*/



/*Write a function that takes two integers for its parameters and prints 
the integer in the given range with the maximum number of divisors, as
well as the number of divisors it has. Have it return both values - the
integer with maximum number of divisors and the number of divisors for it.
Example:
Enter a range: 10 100
60 has the greatest number of divisors with 10 divisors.
*/

#include<iostream>
using namespace std;
void divisors(int, int, int&, int&);
int num_div(int);
int main()
{
	int low, high, max = 0, div = 0;
	cout << "Enter a range: ";
	cin >> low >> high;
	cout << endl;

	divisors(low, high, max, div);

	cout << max << " has the largest number of divisors with " << div << " divisors." << endl << endl;
	system("pause");
	return 0;
}

void divisors(int lo, int hi, int& max, int& div)
{
	
	int max_div;
	max = lo;
	for (int i = lo + 1; i < hi; i++)
	{
		max_div = num_div(i);
		if (max_div > div)
		{
			max = i;
			div = max_div;
		}
	}
	


}

int num_div(int i)
{
	int count = 0;
		for (int j = 2; j < i; j++)
			if (i % j == 0)
				count++;
		return count;

}