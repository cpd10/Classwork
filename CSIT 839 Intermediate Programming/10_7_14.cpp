/*#include<iostream>
using namespace std;
int main()
{
	int nums[4];//nums[4] = { 17, 55, 30, 3}; How to initialize.

	cout << "\nEnter integers: ";
	for (int i = 0; i < 4; i++)
		cin >> nums[i];
	for (int i = 0; i < 4; i++)
		cout << nums[i] << ' ';


	cout << endl;
	system("pause");
	return 0;
}*/


//Searching for an integer in an array.
/*#include<iostream>
using namespace std;
int main()
{
	int nums[4] = {0}, search;

	cout << "\nEnter integers: ";
	for (int i = 0; i < 4; i++)
		cin >> nums[i];
	cout << "\nEnter search value: ";
	for (int i = 0; i < 4; i++)
		if (search == nums[i])
			cout << "\nNumber found at index " << i;


	cout << endl;
	system("pause");
	return 0;
}*/

/*Write a program that reads an unsigned integer between 0 and 255 and prints its equivalent in binary by continueously
dividing the number by 2 and storing its remainders and then printing the stored remainders in reverse order.
Example:
if the integer is 139, 
139/2 = 69 remainder 1
69/2 = 34 remainder 1
34/2 = 17 remainder 0
17/2 = 8 remainder 1
8/2 = 4 remainder 0
4/2 = 2 remainder 0
2/2 = 1 remainder 0
1/2 = 0 remainder 1
Writing the remainders in reverse order: 10001011*/
/*#include<iostream>
using namespace std;
int main()
{
	int num, remain[8] = { 0 }, i = 0;
	cout << "\nEnter an integer: ";
	cin >> num;
	if (num >= 0 && num <= 255)
	{
		do{
			remain[i++] = num % 2;
			num /= 2;
			} while (num > 0);


		for (int i = 7; i >= 0; i--)
			cout << remain[i] << ' ';
	}

	cout << endl;
	system("pause");
	return 0;
}*/

/*Write a program that generates 50 random numbers between 0 and 100 and stores them in an array
of integers. Have the program print the maximum and the index where the maximum is stored in the
array.
Example:
Max = 99 stored at index 43
*/
#include<iostream>
#include<ctime>
using namespace std;
int main()
{
	srand((unsigned)time(0));

	int num, nums[50], max = 0, maxind = 0;
	
	for (int i = 0; i < 50; i++)
	{
		nums[i] = rand() % 101;
		
		cout << nums[i] << ' ';
		
		if (nums[i] > max)
		{
			max = nums[i];
			maxind = i;
		}
	}

	cout << "\nMax = " << max << " stored at index " << maxind << endl;
		

	cout << endl;
	system("pause");
	return 0;
}