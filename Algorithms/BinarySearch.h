#pragma once
class BinarySearch
{
private:

public:
	BinarySearch();
	~BinarySearch();
	int FindValue(int * arr, int left, int right, int value);
	int FindValuewitWhile(int * arr, int left, int right, int value);
	int size = 0;
};

