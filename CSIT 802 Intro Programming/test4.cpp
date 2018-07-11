#include <iostream>
#include <ctime>
using namespace std;
int gen(int, int);
int max(int, int, int);
void main()
{
	int low, high, num;
	srand((unsigned)time(0));

	cout << "Enter the lower and upper limits: ";
	cin >> low >> high;
	cout << "\nEnter of integers to generate: ";
	cin >> num;
	cout << "\nMaximum integer generated was " << max(low, high, num) << "." << endl << endl;

	system("pause");
}


int gen(int low, int high)
{
	int d;
	d = low + rand() % (high - low + 1);
	return d;
}


int max(int low, int high, int num)
{
	int mx = 0;
	for(int i = 0; i < num; i++)
	{
		if(mx < gen(low, high))
			mx = gen(low, high);
	}

	return mx;
}