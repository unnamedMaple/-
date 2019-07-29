#include "Header.h"
int partition(vector<int> &arr, int left, int right)
{

	srand((unsigned)time(NULL));
	int index = rand() % (right-left+1) +left;
	exchange(arr[index], arr[right]);
	int x = arr[right];
	int i = left-1;
	bool equal = true;
	for (int j = left; j < right; j++)
	{
		if (arr[j] != x)
		{
			equal = false;
		}
		if (arr[j] <= x)
		{
			i++;
			exchange(arr[j], arr[i]);
			
		}

	}
	exchange(arr[i + 1], arr[right]);
	/*
	if (equal == true)
	{
		return -1;
	}
	*/
	return i + 1;
}

void quickSort(vector<int> &arr,int left,int right)
{
	if (left<right)
	{
		int q = partition(arr, left, right);
		if (q == -1)
		{
			return;
		}
		quickSort(arr, left, q - 1);
		quickSort(arr, q + 1, right);
	}

	

}