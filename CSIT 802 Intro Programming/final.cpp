#include <iostream>
#include <iomanip>
void total(int, int&, int&);
int points(char);
using namespace std;
void main()
{
	int num, tp = 0, tu = 0;
	cout << "How many classes would you like to calculate GPA for? ";
	cin >> num;
	total(num, tp, tu);
	cout << "\nYour GPA is " << fixed << setprecision(1) << (float)tp / tu << endl << endl;

	system("pause");
}


void total(int num, int& tp, int& tu)
{
	char grade;
	int unit, point;
	for(int i = 1; i <= num; i++)
	{
	cout << "\nLetter grade for class " << i << ": ";
	cin >> grade;
	cout << "How many units was class " << i << " worth? ";
	cin >> unit;
	point = points(grade) * unit;
	tp += point;
	tu += unit;
	}
}


int points(char grade)
{
	int point;
	if(grade == 'a' || grade == 'A')
		point = 4;
	else if(grade == 'b' || grade == 'B')
		point = 3;
	else if(grade == 'c' || grade == 'C')
		point = 2;
	else if(grade == 'd' || grade == 'D')
		point = 1;
	else if(grade == 'f' || grade == 'F')
		point = 0;

	return point;
}