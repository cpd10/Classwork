#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
int main()
{
	int n1, n2, d1, d2, count = 0, num, a, loop = 0;
	char ch;

	srand((unsigned)time(0));

	cout << "Enter number of questions to generate: ";
	cin >> num;
	cout << endl;

	
	cout << "For the following, specify if the first fraction is smaller than, equal to," ;
	cout << "\nor larger than the second. To quit, select quit.";
	
	do
	{
		n1 = 1 + rand() % 10;
		n2 = 1 + rand() % 10;
		d1 = 1 + rand() % 10;
		d2 = 1 + rand() % 10;

		loop++;
		cout << endl << endl << n1 << '/' << d1 << ' ' << n2 << '/' << d2 << endl;
		cout << "\n1. Smaller" << "\n2. Larger" << "\n3. Equal" << "\n4. Quit";
		cout << "\n? ";
		cin >> a;

		if(((n1 * d2) < (n2 * d1)) && a == 1)
		{
			cout << "Correct!" << endl;
			count++;
		}

		else if(((n1 * d2) == (n2 * d1)) && a == 3)
		{
			cout << "Correct!" << endl;
			count++;
		}

		else if(((n1 * d2) > (n2 * d1)) && a == 2)
		{
			cout << "Correct!" << endl;
			count++;
		}

		else if(a == 4)
		{
			loop -= 1;
			break;
		}
		
		else
			cout << "Wrong!";
	}while(loop < num);

	cout << "\nYour score is " << fixed << setprecision(1) << (float)count / loop * 100 << "%" << endl << endl;

	system("pause");
	return 0;
}