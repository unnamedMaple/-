#include "Header.h"
void bubbleSort(vector<int>&arr)
{
	int size = arr.size();
	if (size <= 1)
	{
		return;
	}
	bool isExchanged = false;
	for (int i = 0; i < size; i++)
	{
		isExchanged = false;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				exchange(arr[j], arr[j + 1]);
				isExchanged = true;
			}
		}
		if (isExchanged == false)
		{
			break;
		}
	}
}