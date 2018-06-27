#include "JumpSearch.h"
#include<math.h>


JumpSearch::JumpSearch()
{
}


JumpSearch::~JumpSearch()
{
}

int JumpSearch::FindValue(int * arr, int size, int value)
{
	int block = sqrt(size);

	while (arr[block]<value)
	{
		block += sqrt(size);
		if (block > size)
			return -1;
	}

	// Find value 
	int init = block - sqrt(size);
	for (size_t i = init; i < block; i++)
	{
		if (arr[i] == value)
			return i;
	}

	return -1;
}
