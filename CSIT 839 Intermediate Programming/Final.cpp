/*Darius Hooks
12/16/14
CSIT 839*/
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

struct Item
{
	char description[51];
	double price;
};
int input(Item*[]);
void sort(Item*[], int);
void search(Item*[], int, int, int);
int main()
{
	int size;
	double range1, range2;
	Item* itemptrs[51] = { 0 };

	size = input(itemptrs);
	sort(itemptrs, size);

	cout << "\nSorted list:" << endl << endl;
	for (int i = 0; i < size; i++)
		cout << itemptrs[i]->description << ": $" << fixed << setprecision(2) << itemptrs[i]->price << endl << endl;

	cout << "\nEnter a price range: ";
	cin >> range1 >> range2;

	cout << endl;
	search(itemptrs, range1, range2, size);

	cout << endl;
	system("pause");
	return 0;
}

int input(Item* ipa[])
{
	int count;
	for (count = 0; count < 51; count++)
	{
		ipa[count] = new Item;
		cout << "\nEnter item decscription: ";
		cin.getline(ipa[count]->description, 51, '\n');
		if (strcmp(ipa[count]->description, "") == 0)
			return count;
		cout << "\nEnter price: ";
		cin >> ipa[count]->price;
		cin.ignore();
	}
}

void sort(Item* ipa[], int size)
{
	double tmp;
	bool swap;
	char tmpc[51];
	do
	{
		swap = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (ipa[i]->price > ipa[i + 1]->price)
			{
				tmp = ipa[i]->price;
				ipa[i]->price = ipa[i + 1]->price;
				ipa[i + 1]->price = tmp;
				strcpy_s(tmpc, ipa[i]->description);
				strcpy_s(ipa[i]->description, ipa[i + 1]->description);
				strcpy_s(ipa[i + 1]->description, tmpc);
				swap = true;
			}
		}
	} while (swap);
}

void search(Item* ipa[], int r1, int r2, int size)
{
	fstream itemfile("items.dat", ios::out | ios::binary);
	for (int i = 0; i < size; i++)
	{
		if ((ipa[i]->price > r1) && (ipa[i]->price < r2))
		{
			cout << ipa[i]->description << ": $" << fixed << setprecision(2) << ipa[i]->price << endl << endl;
			itemfile.write((char*)&ipa[i], sizeof(ipa[i]));
		}
	}
	itemfile.close();
}