#include <stdio.h>
#include <iostream>
#include <string>
#include "BinarySearch.h"
#include "JumpSearch.h"

using namespace std;
int compare(const void *one, const void *two)
{
	int a = *((int*)one);
	int b = *((int*)two);
	if (a < b)
		return -1;
	if (a == b)
		return 0;
	return 1;
}

int main()
{
	cout << "Start" << endl;

	int * arr = new int[1000];
	for (int i = 0; i< 1000; i++)
	{
		arr[i] = rand();
	}

	//// Binary Search.
	int value = arr[200];
	qsort(arr, 1000, sizeof(int), compare);


	//int arr[] = { 2, 3, 4, 10, 40 };
	//int n = sizeof(arr) / sizeof(arr[0]);
	
	BinarySearch search;
	int result = search.FindValue(arr, 0, 999, value);
	result = search.FindValuewitWhile(arr, 0, 999, value);

	int arr1[] = { 2, 3, 4, 10, 40 };

	JumpSearch jsearch;
	int stat = jsearch.FindValue(arr, 1000, value);


	cout << "End" << endl;
	return 0;
}

