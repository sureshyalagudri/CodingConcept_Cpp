#include "BinarySearch.h"



BinarySearch::BinarySearch()
{
}


BinarySearch::~BinarySearch()
{
}

int BinarySearch::FindValue(int * arr, int left, int right, int value)
{
	if (right >= left)
	{
		int mid = left + (right - left) / 2;

		if (arr[mid] == value)
		{
			return mid;
		}

		if (arr[mid] > value)
		{
			return FindValue(arr, left, mid - 1, value);
		}
		else
		{
			return FindValue(arr, mid + 1, right, value);
		}
	}
	return -1;
}

int BinarySearch::FindValuewitWhile(int * arr, int left, int right, int value)
{
	while (right >= left)
	{
		int mid = left + (right - left) / 2;
		
		if (arr[mid] == value)
		{
			return mid;
		}

		if (arr[mid] > value)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	return -1;
}
