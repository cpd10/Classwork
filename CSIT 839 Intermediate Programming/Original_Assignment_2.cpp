#include<iostream>
using namespace std;
int main_menu();
int getprimes(int[], int, int);
bool is_prime(int);
int main()
{
	int upper, primes[1001], fibos[1001], prm_fibos[501], prm_nfibos[501], fibos_nprm[501];
	cout << "Enter the upper limit of integers to generate: ";
	cin >> upper;
	
	switch (main_menu)
	{
	case 1: cout << getprimes(primes, 1000, upper);
			break;
	}
	



	system("pause");
	return 0;
}

int main_menu()
{
	int num;
	cout << "Choose one of the following by entering the corresponding number: ";
	cout << "\n1. Display prime numbers" << "\n2. Display Fibonacci numbers" <<
		"\n3. Display prime numbers that are also part of the Fibonacci series" <<
		"\n4. Display prime numbers that are not part of the Fibonacci series" <<
		"\n5. Display Fibonacci numbers that are not prime numbers" <<
		"\n6. Search for a number" <<
		"\n7. Quit";
	cout << "\nEnter Selection: ";
	cin >> num;
	return num;

}

int getprimes(int prime[], int size, int up)
{
	for


}