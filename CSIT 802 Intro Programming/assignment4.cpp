/*Darius Hooks*/
#include <iostream>
#include <ctime>
#include <string>
using namespace std;
int main()
{
	string p1, p2, p3, p4, p5, p6, p7, p8, p9, p10;
	int q, q1 = 0, a, total = 0, count = 0, loop = 0;

	p1 =	"George Washington (1789-1797)";
	p2 =	"John Adams (1797-1801)";
	p3 = 	"Thomas Jefferson (1801-1809)";
	p4 = 	"James Madison (1809-1817)";
	p5 =	"James Monroe (1817-1825)";
	p6 =	"John Quincy Adams (1825-1829)";
	p7 =	"Andrew Jackson (1829-1837)";
	p8 =	"Martin Van Buren (1837-1841)";
	p9 =	"William H. Harrison (1841)";
	p10 = 	"John Tyler (1841-1845)";
	
	srand((unsigned)time(0));
	
	cout << "Enter the order for each of the following presidents: " << endl << endl;

	do
	{
		q = 1 + rand() % 10;
		loop++;
		
		if(q == q1)
		{
			cout << loop << ". President was repeated, another will be randomly selected:" << endl << endl;
			q = 1 + rand() % 10;
		}
		
		switch(q)
		{
		case 1: cout << loop << ". " << p1 << ": ";
				break;
		case 2: cout << loop << ". " << p2 << ": ";
				break;
		case 3: cout << loop << ". " << p3 << ": ";
				break;
		case 4: cout << loop << ". " << p4 << ": ";
				break;
		case 5: cout << loop << ". " << p5 << ": ";
				break;
		case 6: cout << loop << ". " << p6 << ": ";
				break;
		case 7: cout << loop << ". " << p7 << ": ";
				break;
		case 8: cout << loop << ". " << p8 << ": ";
				break;
		case 9: cout << loop << ". " << p9 << ": ";
				break;
		case 10: cout << loop << ". " << p10 << ": ";
				break;
		}
		
		
		
		cin >> a;

		
		
		if(a == q)
			{
				cout <<  "   Right!" << endl << endl;
				total++;
			}
				

		else if(a != q)
			{
				while(count < 2)
				{
					cout << "   Wrong! Try again: ";
					cin >> a;
					count++;
				
					if(a == q)
					{
						cout << "   Right!" << endl << endl;
						total++;
						count -= 2;
						break;
					}

					else if(count >= 2)
					{
						cout << "   Wrong! The correct answer is " << q << endl << endl;
						count -= 2;
						break;
					}

				}
			}
		q1 = q;
	}while(loop < 10);

	
	cout << "\nYou answered " << total << " of " << loop << " correctly." << endl << endl;
	system("pause");
	return 0;
}

