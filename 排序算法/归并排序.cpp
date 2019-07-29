#include"Header.h"

void submergeSort(vector<int>&arr, vector<int>&tmpmem,int left, int right)
{
	if (left >= right)
	{
		return;
	}

	if (right - left == 1)
	{
		
		if (arr[right] < arr[left])
		{
			exchange(arr[left], arr[right]);
		}
		return;
	}


	int mid = left + (right - left) / 2;
	submergeSort(arr, tmpmem, left, mid);
	submergeSort(arr, tmpmem,mid + 1, right);
	int i = left;
	int j = mid + 1;
	int index;
	for ( index = left; index <= right; index++)
	{
		if (i<=mid&&j<=right)
		{
			if (arr[i] <= arr[j]){
				tmpmem[index] = arr[i];
				i++;
			}
			else
			{
				tmpmem[index] = arr[j];
				j++;
			}
		}
		else
		{
			break;
		}
		
	}

	while (i <= mid)
	{
		tmpmem[index] = arr[i];
		index++;
		i++;
	}
	while (j <= right)
	{
		tmpmem[index] = arr[j];
		index++;
		j++;
	}


	for (index = left; index <= right; index++)
	{
		arr[index] = tmpmem[index];

	}
	

}

void mergeSort(vector<int>&arr)
{
	int size = arr.size();
	if (size <= 1)
	{
		return;
	}
	vector<int>tmpmem(arr.size(), 0);
	submergeSort(arr, tmpmem, 0,size-1);
}