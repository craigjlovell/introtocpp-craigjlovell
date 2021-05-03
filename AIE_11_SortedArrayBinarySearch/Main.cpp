#include <iostream>
#include <math.h>

bool BinarySearch(int* arr, int size, int searchValue)
{
	// TODO: write your code here
	int left = 0;
	int right = size - 1;
	int middle = 0;


	while (left <= right)
	{
		middle = floor(((left + right) / 2));
		if (arr[middle] == searchValue)
		{
			return true;
		}
		else if (arr[middle] > searchValue)
		{
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
	}
	return false;
}

int main()
{
	const int ARR_SIZE = 8;
	int arr1[ARR_SIZE] = { 1, 3, 5, 7, 9, 11, 13, 15 };

	std::cout << (BinarySearch(arr1, ARR_SIZE, 9) ? "Found" : "Not Found") << std::endl;
	std::cout << (BinarySearch(arr1, ARR_SIZE, 1) ? "Found" : "Not Found") << std::endl;
	std::cout << (BinarySearch(arr1, ARR_SIZE, 15) ? "Found" : "Not Found") << std::endl;
	std::cout << (BinarySearch(arr1, ARR_SIZE, 0) ? "Found" : "Not Found") << std::endl;

	return 0;
}

