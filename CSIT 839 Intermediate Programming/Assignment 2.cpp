/*
Darius Hooks
CSIT 839
Assignment 2
*/
#include<iostream>
using namespace std;
int menu();
void search(char [], char, int&, int&);
void change(char [], int&, char);
void beginning(char[], int);
void ending(char[], int);
void all(char[], int&, int&);
void null_(char[]);
int main()
{
	char str[101], srch, ch;
	int count = 0, index = 0, beg, end, eind = 0, loop = 0;

	do{
		cout << "Please enter a string: ";
		cin.getline(str, 101, '\n');
		switch (menu())
		{
			case 1: cout << "\nEnter a character to search for: ";
				cin >> srch;
				search(str, srch, count, index);
				if (index >= 0 && count == 1 && index < strlen(str))
				{
					cout << "\nThere is " << count << " " << srch << " in " << '"' << str << '"'
						<< " at index " << index << endl << endl;
				}

				else if (index >= 0 && count > 0 && index < strlen(str))
				{
					cout << "\nThere are " << count << " " << srch << "'s in " << '"' << str << '"'
						<< " with the first at index " << index << endl << endl;
				}

				else
					cout << "\nThere are no " << srch << "'s in " << '"' << str << '"' << endl << endl;
				break;
			case 2: do{
				cout << "\nWhat is the index of the character you want to change? ";
				cin >> index;
				cout << "\nWhat character do you want in that position? ";
				cin >> ch;
				change(str, index, ch);
				} while (index > strlen(str));
				break;
			case 3: do{
				cout << "\nHow many characters from the beginning of the string do you want to display? ";
				cin >> beg;
				beginning(str, beg);
				} while (beg > strlen(str));
				break;
			case 4: do{
				cout << "\nHow many characters from the end of the string do you want to display? ";
				cin >> end;
				ending(str, end);
				} while (end > strlen(str));
				break;
			case 5: do{
				cout << "\nPlease enter the beginning index: ";
				cin >> index;
				cout << "\nPlease enter the ending index: ";
				cin >> eind;
				all(str, index, eind);
				} while (index > strlen(str) || eind > strlen(str));
				break;
			case 6: null_(str);
					break;
			case 7: loop++;
					break;
		}
		cin.ignore();
	} while (loop != 1);
	cout << endl;
	system("pause");
	return 0;
}


int menu()
{
	int answer;
	cout << "\nMake a selection:" << endl <<
		"\n1. Search for a character in the string" <<
		"\n2. Change a character within the string" <<
		"\n3. Display the first n characters of the string" <<
		"\n4. Display the last n character of the string" <<
		"\n5. Display all characters that lie between two given indices" <<
		"\n6. Null the string" <<
		"\n7. Exit";
	cout << "\n\nChoice: ";
	cin >> answer;
	return answer;
}

void search(char str[], char srch, int& count, int& index)
{
	int i;
	count = 0;

	for (i = 0; str[i] != '\0' && str[i] != srch; i++)

	index = i + 1;
	count++;

	for (int j = i + 1; str[j] != '\0'; j++)
	{
		if (str[j] == srch)
			count++;
		else if (count == 0)
			index = -1;
	}

}

void change(char str[], int& index, char ch)
{
		int i;
		for (i = 0; str[i] != '\0'; i++)
			str[index] = ch;
		if (index < strlen(str))
			cout << "\nThe new string is " << '"' << str << '"' << endl << endl;
		else
			cout << "\nThat position is outside the bounds of the string. String unchanged." << endl << endl;
}

void beginning(char str[], int beg)
{
	int i;
		
	for (i = 0; str[i] != '\0' && i < beg; i++)
	{
		if (beg < strlen(str))
			cout << str[i];
		else
		{
			cout << "\nError: Too many characters.";
			break;
		}
	}

	cout << endl << endl;
}

void ending(char str[], int end)
{
	if (end < strlen(str))
		cout << str + strlen(str) - end;
	else
		cout << "\nError: Too many characters." << endl;
	cout << endl << endl;
}

void all(char str[], int& index, int& eind)
{
	for (int i = index; i <= eind; i++)
	{
		if (index < strlen(str) && eind < strlen(str))
			cout << str[i];
		else if (index < strlen(str) && eind > strlen(str))
		{
			cout << "\nError: one or more indices are outside the bounds of the array." << endl;
			break;
		}
		else
		{
			cout << "\nError: one or more indices are outside the bounds of the array." << endl;
			break;
		}
	}
	cout << endl << endl;
}

void null_(char str[])
{
	if (strlen(str) > 0)
	{
		str = "";
		cout << str << "\nThe string is now Null." << endl << endl;
	}
	else
		cout << "\nThe string is already Null. Nothing changed." << endl << endl;

}