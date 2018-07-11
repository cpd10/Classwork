/*Darius Hooks*/
#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	srand((unsigned)time(0));

	int day, month, year;

	day = 1 + rand() % 32;
	month = 1 + rand() % 12;
	
		
	if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
		{
			cout << "Generated " << month << '/' << day << " which is invalid." << endl;
			
			day = 1 + rand() % 31;
			month = 1 + rand() % 12;
			
			cout << "Generated the alternate of " << month << '/' << day << " as a new holiday." << endl;
		}

	else if((month == 1 && day == 1) || (month == 5 && day == 26) || (month == 7 && day == 4) 
				|| (month == 9 && day == 12) || (month == 11 && day == 25) || (month == 12 && day == 25))
			{
				cout << "Generated " << month << '/' << day << " which is a holiday." << endl;
				
				day = 1 + rand() % 31;
				month = 1 + rand() % 12;
				cout << "Generated the alternate of " << month << '/' << day << " as a new holiday." << endl;
			}
	
	else if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
	{
		cout << "Generated " << month << '/' << day << " which is invalid." << endl;
		
		day = 1 + rand() % 31;
		month = 1 + rand() % 12;
		
		cout << "Generated the alternate of " << month << '/' << day << "as a new holiday." << endl;
		
	}

	else if(month == 2 && day > 29)
	{
		cout << "Generated " << month << '/' << day << " which is invalid." << endl;
		
		day = 1 + rand() % 31;
		month = 1 + rand() % 12;
		
		cout << "Generated the alternate of " << month << '/' << day << " as a new holiday." << endl;
		
	}

	else if(month == 2 && day == 29)
	{
			cout <<"Generated " << month << '/' << day << endl;
			cout << "Enter current year: ";
			cin >> year;
				
			if(year % 4 != 0)
			{
				cout << year << " is not a leap year so " << month << '/' << day << " is invalid." << endl;

				day = 1 + rand() % 31;
				month = 1 + rand() % 12;
		
				cout << "Generated the alternate of " << month << '/' << day << " as a new holiday." << endl;
			}

			else if(year % 4 == 0)
			{
				cout << year << " is a leap year." << endl;
				cout << month << '/' << day << " is a new holiday." << endl;
			}
	}
	
	else 
		cout << "Generated " << month << '/' << day << " as a new holiday." << endl;

	system("pause");
	return 0;
}