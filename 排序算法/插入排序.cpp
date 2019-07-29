#include "Header.h"

void insertSort(vector<int> &arr)
{
	int size = arr.size();
	if (size <= 1)
	{
		return;
	}

	for (int i = 1; i < size; i++)
	{

		int j = i;
		while (j>0 && arr[j] < arr[j - 1])
		{
			exchange(arr[j], arr[j - 1]);
			j--;
		}
	}
}