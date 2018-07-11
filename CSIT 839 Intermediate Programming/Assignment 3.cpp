//Darius Hooks
//Assignment 3

#include<iostream>
#include<ctime>
using namespace std;
void twodsort(int [][15], int [], int, int, bool);
int search(int [][15], int, int&, int&, int);
void randomize(int [][15], int, int);
void onedsort(int [],int, int);
int main()
{
	int nums[15][15], num[225], option, val, count1 = 0, rows = 0, columns = 0, count, row_size;
	bool sorting;
	srand((unsigned)time(0));

	/*Populates the 2d array with random numbers between 1-100
	and also stores them into a 1d array then prints the 
	2d array with the random numbers.*/
	cout << "Array populated with random numbers from 1-100:" << endl << endl;
	for (int row = 0; row < 15; row++)
	{
		for (int col = 0; col < 15; col++)
		{
			nums[row][col] = rand() % 101;
			num[count1] = nums[row][col];
			count1++;
			cout << nums[row][col] << ' ';
		}
		cout << endl;
	}

	/*A sorting menu prints and asks user to select
	a sorting option. If selection is invalid program
	will ask user to select an option until selection
	is valid.*/
	cout << "\nSorting Options";
	cout << "\n\n1. Smallest to Largest";
	cout << "\n2. Largest to Smallest";
	cout << "\n\nSelect sorting: ";
	cin >> option;
	while (option > 2 || option < 1)
	{
		cout << "Invalid!";
		cout << "\nSelect sorting: ";
		cin >> option;
	}

	if (option == 1)
		sorting = true;
	else if (option == 2)
		sorting = false;
	
	twodsort(nums, num, 15, 15, sorting);//2d array sort function

	cout << endl;

	cout << "\nArray sorted:" << endl << endl;
	/*Sorted 2d array*/
	for (int row3 = 0; row3 < 15; row3++)
	{
		for (int col3 = 0; col3 < 15; col3++)
		{
			cout << nums[row3][col3] << ' ';
		}
		cout << endl;
	}

	cout << "\nEnter value to search for: ";
	cin >> val;

	count = (search(nums, 15, rows, columns, val));//Binary search function
	if (count == -1)
		cout << endl << val << " could not be found." << endl;
	else if (count == 1)
		cout << endl << val << " was first found at row " << rows << " column " << columns
		<< ", and was generated " << count << " time." << endl;
	else
		cout << endl << val << " was first found at row " << rows << " column " << columns
		<< ", and was generated " << count << " times." << endl;

	cout << "\nEnter number of rows from the bottom to randomize: ";
	cin >> row_size;
	while (row_size >= 15 || row_size < 0)
	{
		cout << "Invalid!";
		cout << "\nEnter number of rows from the bottom to randomize: ";
		cin >> row_size;
	}
	
	cout << endl;
	randomize(nums, 15, row_size);//Randomize function
	
	cout << endl;
	system("pause");
	return 0;
}

void twodsort(int nums[][15], int num[], int row, int col, bool sort)
{
	int tmp, count2 = 0;
	bool swap;
	if (sort == true)
	{
		do
		{
			swap = false;
			for (int i = 0; i < row * col - 1; i++)
				if (num[i] > num[i + 1])
				{
				tmp = num[i];
				num[i] = num[i + 1];
				num[i + 1] = tmp;
				swap = true;
				}
		} while (swap == true);
		
		/*The sorted 1d array is stored back into the 2d array
		and a sorted 2d array is printed.*/
		for (int row2 = 0; row2 < row; row2++)
		{
			for (int col2 = 0; col2 < col; col2++)
			{
				nums[row2][col2] = num[count2];
				count2++;
			}
		}
	}

	else if (sort == false)
	{
		do
		{
			swap = false;
			for (int i = 0; i < row * col - 1; i++)
				if (num[i] < num[i + 1])
				{
				tmp = num[i];
				num[i] = num[i + 1];
				num[i + 1] = tmp;
				swap = true;
				}
		} while (swap == true);

		/*The sorted 1d array is stored back into the 2d array
		and a sorted 2d array is printed.*/
		for (int row2 = 0; row2 < 15; row2++)
		{
			for (int col2 = 0; col2 < 15; col2++)
			{
				nums[row2][col2] = num[count2];
				count2++;
			}
		}
	}
}

int search(int nums[][15], int rows, int& rows_, int& columns, int value)
{
	int occur = 0;
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < rows; col++)
		{
			if (nums[row][col] == value && occur == 0)
			{
				rows_ = row;
				columns = col;
				occur++;
			}
			else if (nums[row][col] == value)
			{
				occur++;
			}
		}
	}
	if (occur == 0)
		return -1;
	else
		return occur;
}

void randomize(int nums[][15], int max_rows, int size)
{
	int num_random[225];
	int count1 = 0, count2 = 0;
	
	for (int row = max_rows - size; row < max_rows; row++)
	{
		for (int col = 0; col < max_rows; col++)
		{
			nums[row][col] = rand() % 101;
			num_random[count1] = nums[row][col];
			count1++;
		}
	}

	cout << "\nArray with randomized rows:" << endl << endl;
	/*Prints the 2d array with the randomized rows.*/
	for (int j = 0; j < max_rows; j++)
	{
		for (int k = 0; k < max_rows; k++)
		{
			cout << nums[j][k] << ' ';
		}
		cout << endl;
	}
		
	onedsort(num_random, size, max_rows);//1d array sort

	/*The assorted rows are stored back into the 2d array.*/
	for (int row = max_rows - size; row < max_rows; row++)
	{
		for (int col = 0; col < max_rows; col++)
		{
				nums[row][col] = num_random[count2];
				count2++;
		}
	}

	cout << endl << endl;
	cout << "Array with randomized rows sorted:" << endl << endl;
	/*The 2d array with the newly sorted rows is printed.*/
	for (int m = 0; m < max_rows; m++)
	{
		for (int n = 0; n < max_rows; n++)
		{
			cout << nums[m][n] << ' ';
		}
		cout << endl;
	}
}

void onedsort(int random[], int size, int csize)
{
	int tmp;
	bool swap;
	do
	{
		swap = false;
		for (int i = 0; i < size * csize - 1; i++)
			if (random[i] > random[i + 1])
			{
				tmp = random[i];
				random[i] = random[i + 1];
				random[i + 1] = tmp;
				swap = true;
			}
	} while (swap == true);
}