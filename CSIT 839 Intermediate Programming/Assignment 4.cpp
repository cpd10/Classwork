/*Darius Hooks
  Assignment 4*/

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
enum Section {ORCHESTRA, FRONT, MIDDLE, BACK};
const double PRICE[] {150.00, 100.00, 75.00, 50.00};
struct date
{
	int month, day, year;
};
struct seat
{
	char rows;
	int columns;
	Section section;
	bool assigned;
	string name;
	date signdate;
};
void intialize(seat [][51], int);	//Initializes all data within the seat structure
void display_all(seat [][51], int);	//Displays all data that was initialized
void display_assgn(seat [][51], int);	//Displays all assigned seats
void sort(seat[][51], int);	//Sorts the assigned seats
void search(seat[][51], int, string);	//Searches all seats for specified customer
string prnt_section(seat[][51], int, int, int);	//To display the name of the section
int main()
{
	int price, pr, row, col;
	int orch_col = 0, front_col = 0, mid_col = 0, back_col = 0;	//Starting column index
	int orch_row = 0, front_row = 5, mid_row = 10, back_row = 20;	//Starting row index for each section
	char ch, again;
	string search_name;
	seat seating[26][51];
	intialize(seating, 26);
	display_all(seating, 26);

	do
	{
		cout << "Enter seat price: $";
		cin >> price;
		cin.ignore();
		
		if (price == 150)	//For orchestra
		{
			orch_col++;
			pr = ORCHESTRA;
			if (orch_col > 50)	//Resets row and column to display the next row of seats within orchestra section
			{
				orch_row++;	//To go to the next row
				orch_col = 1;	//Resets the column index for seats in the next row
			}
			row = orch_row;
			col = orch_col;
			cout << "Enter name: ";
			getline(cin, seating[row][col].name);
			cout << "Enter date: ";
			cin >> seating[row][col].signdate.month >> ch
				>> seating[row][col].signdate.day >> ch 
				>> seating[row][col].signdate.year;
			seating[row][col].assigned = true;
		}
		else if (price == 100)	//For front
		{
			front_col++;
			pr = FRONT;
			if (front_col > 50)	//Resets row and column to display the next row of seats within front section
			{
				front_row++;
				front_col = 1;
			}
			row = front_row;
			col = front_col;
			cout << "Enter name: ";
			getline(cin, seating[row][col].name);
			cout << "Enter date: ";
			cin >> seating[row][col].signdate.month >> ch
				>> seating[row][col].signdate.day >> ch
				>> seating[row][col].signdate.year;
			seating[row][col].assigned = true;
		}
		else if (price == 75)	//For Middle
		{
			mid_col++;
			pr = MIDDLE;
			if (mid_col > 50)	//Resets row and column to display the next row of seats within middle section
			{
				mid_row++;
				mid_col = 1;
			}
			row = mid_row;
			col = mid_col;
			cout << "Enter name: ";
			getline(cin, seating[row][col].name);
			cout << "Enter date: ";
			cin >> seating[row][col].signdate.month >> ch
				>> seating[row][col].signdate.day >> ch
				>> seating[row][col].signdate.year;
			seating[row][col].assigned = true;
		}
		else if (price == 50)	//For Back
		{
			back_col++;
			pr = BACK;
			if (back_col > 50)	//Resets row and column to display the next row of seats within back section
			{
				back_row++;
				back_col = 1;
			}
			row = back_row;
			col = back_col;
			cout << "Enter name: ";
			getline(cin, seating[row][col].name);
			cout << "Enter date: ";
			cin >> seating[row][col].signdate.month >> ch
				>> seating[row][col].signdate.day >> ch
				>> seating[row][col].signdate.year;
			seating[row][col].assigned = true;
		}
		//Newly assigned seat data displayed
		cout << "Assigned " << char(seating[row][col].rows) << seating[row][col].columns << ". Section "
			<< prnt_section(seating, 26, row, col) << ", Price $" << int(PRICE[pr]) << " to " << seating[row][col].name << ", "
			<< seating[row][col].signdate.month << '/' << seating[row][col].signdate.day << '/'
			<< seating[row][col].signdate.year;
		cout << "\n\nAssign another [y/n]? ";
		cin >> again;
		cin.ignore();
		cout << endl;
	} while (again == 'y' || again == 'Y');

	cout << "Assigned Seats:" << endl << endl;
	display_assgn(seating, 26);	//Displays all assigned seats

	cout << "\nAssigned Seats(sorted by name):" << endl << endl;
	sort(seating, 26);

	cout << "\nEnter a name to search for: ";
	getline(cin, search_name);
	search(seating, 26, search_name);
	
	cout << endl;
	system("pause");
	return 0;
}
void intialize(seat seating[][51], int size)
{
	int i = 65;	//To convert to letters A - Z
	for (int row = 0; row < size; row++)
	{
		for (int col = 1; col < 51; col++)
		{
			seating[row][col].rows = i;
			seating[row][col].columns = col;
			seating[row][col].name = "";
			seating[row][col].assigned = false;
			seating[row][col].signdate.month = 1;
			seating[row][col].signdate.day = 1;
			seating[row][col].signdate.year = 1900;
			if (i < 70)
				seating[row][col].section = ORCHESTRA;
			else if (i < 75 && i >= 70)
				seating[row][col].section = FRONT;
			else if (i < 85 && i >= 75)
				seating[row][col].section = MIDDLE;
			else if (i < 91 && i >= 85 )
				seating[row][col].section = BACK;
		}
		i++;
	}
}

void display_all(seat seating[][51], int size)
{
	int j = ORCHESTRA;	//Price for orchestra
	for (int row = 0; row < size; row++)
	{
		if (row >= 5 && row < 10)	//Price for front
			j = FRONT;
		else if (row >= 10 && row < 20)	//Price for middle
			j = MIDDLE;
		else if (row >= 20 && row < 26)	// Price for back
			j = BACK;
		for (int col = 1; col < 51; col++)
		{
			cout << char(seating[row][col].rows) << seating[row][col].columns << ". Section "
				<< prnt_section(seating, 26, row, col) << ", Price $" << int(PRICE[j]) << ", "
				<< seating[row][col].name << seating[row][col].signdate.month << '/' << seating[row][col].signdate.day << '/' 
				<< seating[row][col].signdate.year << endl;
		}
		cout << endl;
	}
}

void display_assgn(seat seating[][51], int size)
{
	int j = ORCHESTRA, total = 0;
	for (int row = 0; row < size; row++)
	{
		if (row >= 5 && row < 10)
			j = FRONT;
		else if (row >= 10 && row < 20)
			j = MIDDLE;
		else if (row >= 20 && row < 26)
			j = BACK;
		for (int col = 1; col < 51; col++)
		{
			if (seating[row][col].assigned == true)
			{
				cout << char(seating[row][col].rows) << seating[row][col].columns << ". Section "
					<< prnt_section(seating, 26, row, col) << ", Price $" << int(PRICE[j]) << " to " << seating[row][col].name << ", "
					<< seating[row][col].signdate.month << '/' << seating[row][col].signdate.day << '/'
					<< seating[row][col].signdate.year << endl;
				total += PRICE[j];
			}	
		}
	}

	cout << "\nTotal: $" << fixed << setprecision(2) << float(total) << endl;
}

void sort(seat seating[][51], int size)
{
	string name_tmp;	//To swap names
	int tmp;	//To swap dates and rows
	Section sect_tmp;	//To swap section
	bool swap = false;
	for (int row = 0; row < size; row++)
	{
		for (int col = 1; col < 51; col++)
		{
			if (seating[row][col].assigned == true && seating[row][col + 1].assigned == true)
			{
				if (seating[row][col].name > seating[row][col + 1].name)
				{
					name_tmp = seating[row][col].name;	//Swap names
					seating[row][col].name = seating[row][col + 1].name;
					seating[row][col + 1].name = name_tmp;
					tmp = seating[row][col].rows;	//Swap rows
					seating[row][col].rows = seating[row][col + 1].rows;
					seating[row][col + 1].rows = tmp;
					tmp = seating[row][col].columns;	//Swap columns
					seating[row][col].columns = seating[row][col + 1].columns;
					seating[row][col + 1].columns = tmp;
					sect_tmp = seating[row][col].section;	//Swap section
					seating[row][col].section = seating[row][col + 1].section;
					seating[row][col + 1].section = sect_tmp;
					tmp = seating[row][col].signdate.month;	//Swap date
					seating[row][col].signdate.month = seating[row][col + 1].signdate.month;
					seating[row][col + 1].signdate.month = tmp;
					tmp = seating[row][col].signdate.day;
					seating[row][col].signdate.day = seating[row][col + 1].signdate.day;
					seating[row][col + 1].signdate.day = tmp;
					tmp = seating[row][col].signdate.year;
					seating[row][col].signdate.year = seating[row][col + 1].signdate.year;
					seating[row][col + 1].signdate.year = tmp;
					swap = true;
				}
			}
		}
	}
	display_assgn(seating, size);
}

void search(seat seating[][51], int size, string sname)
{
	int j = ORCHESTRA, found = 0;
	for (int row = 0; row < size; row++)
	{
		if (row >= 5 && row < 10)
			j = FRONT;
		else if (row >= 10 && row < 20)
			j = MIDDLE;
		else if (row >= 20 && row < 26)
			j = BACK;
		for (int col = 1; col < 51; col++)
		{
			if (sname == seating[row][col].name)
			{
				cout << endl << sname << " found at: "
					<< char(seating[row][col].rows) << seating[row][col].columns << ". Section "
					<< prnt_section(seating, 26, row, col) << ", Price $" << int(PRICE[j]) << ", purchase date "
					<< seating[row][col].signdate.month << '/' << seating[row][col].signdate.day << '/'
					<< seating[row][col].signdate.year << endl;
				found++;
			}
		}
	}
	if (found < 1)
		cout << "\nName not found." << endl;
}

string prnt_section(seat seating[][51], int size, int row_, int col_)
{
	string s;
	switch (seating[row_][col_].section)
	{
		case 0: s = "ORCHESTRA";
			break;
		case 1: s = "FRONT";
			break;
		case 2: s = "MIDDLE";
			break;
		case 3: s = "BACK";
			break;
	}
	return s;
}