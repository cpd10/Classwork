/*Write a program in C++ that generates 25 integers between 0 and 100 and stores them in an array of integers and prints the array elements. 
You will then write a function that will receive the array and pick out the largest element and place it at the last position in the array. 
For example, if the largest is 100, it will swap it with the last element to make 100 the last. The function can repeat this any number of times. 
For example, after moving the largest to the last position, it can do the same with the next largest element.
After printing the generated integers, ask the user how many of the largest array elements he or she wants to move to the end of the array 
and pass it along with the array and its size to the function. Then, after the function returns, print the array elements in main.
Example:
List of numbers generated:
76 81 99 51 11 70 92 23 64 49 10 7 16 88 12 24 51 19 49 17 32 66 4 1 23
 
How many of the largest do you want moved to the end of the list?  3
 
Modified list after moving 3 elements to the end of the list:
76 81 51 11 70 23 64 49 10 7 16 12 24 51 19 49 17 32 66 4 1 23 88 92 99
 
Hint: compare every two adjacent elements such as 1st with 2nd, 2nd with 3rd, 3rd with 4th, etc. If the first is larger than the next, swap them. 
In the above example, 76 is not larger than 81 so you don't swap, but 81 is larger than 51 so you swap them. 
Then, you compare 81 which is the new 3rd element with the 4th which is 11 and swap again and so on. Keep doing that until you compare the one next to the last with the last. 
If you can do that once, you can repeat it as many times as required. In the above example, this was repeated 3 times.
You must use loops to avoid repeating code. You must also use a function as described. Printing of the array elements must be done in main.*/
#include<iostream>
#include<ctime>
using namespace std;
void array_(int [], int, int);
int main()
{
	int random[25], ans, size = 25;
	
	srand((unsigned)time(0));
	
	for (int i = 0; i < size; i++)
	{
		random[i] = rand() % 101;
		cout << random[i] << ' ';
	}

	cout << "\n\nHow may time to move max? ";
	cin >> ans;
	
	array_(random, size, ans);

	cout << endl;
	for (int i = 0; i < size; i++)
		cout << random[i] << ' ';
	
	cout << endl;
	system("pause");
	return 0;
}

void array_(int random[], int size, int ans)
{
	int max = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < ans; j++)
		{
			if (random[i] > random[i++])
			{
				random[i++] = random[i];
				random[i] = random[i++];

			}
			
		}
}