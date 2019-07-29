#include "Header.h"
void selectSort(vector<int>&arr)
{
	int size = arr.size();
	if (size <= 1)
	{
		return;
	}

	int index;
	for (int i = 0; i < size; i++)
	{
		index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[index])
			{
				index = j;
			}
		}
		if (index != i)
		{
			exchange(arr[i], arr[index]);
		}
		
	}
}