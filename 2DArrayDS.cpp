
/*
	Given a 6x6 2D Array, arr:

		1 1 1 0 0 0
		0 1 0 0 0 0
		1 1 1 0 0 0
		0 0 0 0 0 0
		0 0 0 0 0 0
		0 0 0 0 0 0

	An hourglass in "A" is a subset of values with indices falling in this pattern in arr's graphical representation:

		a b c
		  d
		e f g

	There are 16 hourglasses in arr. An hourglass sum is the sum of an hourglass' values. 
	Calculate the hourglass sum for every hourglass in arr, then print the maximum hourglass sum. The array will always be 6x6.

*/

#include <iostream>

int arr[6][6] = {
					{1, 1, 1, 0, 0, 0},
					{0, 1, 0, 0, 0, 0},
					{1, 1, 1, 0, 0, 0},
					{0, 0, 2, 4, 4, 0},
					{0, 0, 0, 2, 0, 0},
					{0, 0, 1, 2, 4, 0}
				};

void PrintHourGlass()
{
	for (int i = 0; (i + 2) < 6; ++i)
	{
		for (int j = 0; (j + 2) < 6; ++j)
		{
			std::cout << arr[i][j] << "  " << arr[i][j + 1] << "  " << arr[i][j + 2] << "\n";
			std::cout << "   " << arr[i + 1][j + 1] << "\n";
			std::cout << arr[i + 2][j] << "  " << arr[i + 2][j + 1] << "  " << arr[i + 2][j + 2] << "\n";

			int sum = (arr[i][j] + arr[i][j + 1] + arr[i][j + 2]) + arr[i + 1][j + 1] + (arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2]);
			std::cout << "\nSum - " << sum <<"\n\n";
		}
		std::cout << "\n-----------------\n";
	}
}

int GetMaxHourGlassSum()
{
	int sum = INT_MIN;
	int max_sum = INT_MIN;

	for (int i = 0; (i + 2) < 6; ++i)
	{
		for (int j = 0; (j + 2) < 6; ++j)
		{
			sum = (arr[i][j] + arr[i][j + 1] + arr[i][j + 2]) + arr[i + 1][j + 1] + (arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2]);
			if (sum > max_sum)
				max_sum = sum;
		}
	}	
	return max_sum;
}

int main()
{
	PrintHourGlass();
	std::cout << "Max hour glass sum - " << GetMaxHourGlassSum();
	return 0;
}