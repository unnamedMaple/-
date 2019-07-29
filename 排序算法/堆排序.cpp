#include "Header.h"
void heaplify(vector<int>&arr, int i,int len)
{
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest = i;
	if (left < len-1 && arr[largest] < arr[left])
	{
		largest = left;
	}

	if (right < len-1 && arr[largest] < arr[right])
	{
		largest = right;
	}

	if (largest != i)
	{
		exchange(arr[i], arr[largest]);
		heaplify(arr, largest, len);
	}

}

void buildHeap(vector<int>&arr)
{
	int len = arr.size();
	for (int i = len / 2; i >= 0; i--)
	{
		heaplify(arr, i, len);
	}
}

void heapSort(vector<int>&arr)
{
	buildHeap(arr);
	int len = arr.size();
	for (int i = 0; i < arr.size(); i++)
	{
		exchange(arr[0], arr[len - 1]);
		heaplify(arr, 0, len - 1);
		len--;
	}
	
}

