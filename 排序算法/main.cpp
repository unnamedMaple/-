
#include "Header.h"

void testQuickSort(vector<int>&arr);
int main()
{
	//vector<int>nums = { 3, 5, 7, 56, 89, 23, 11, 4 };
	//<int>test(nums.begin(), nums.end());
	//int right = test.size() - 1;
	//quickSort(test, 0, right);
	//bubbleSort(test);
	//insertSort(test);
	//selectSort(test);
	//heapSort(test);
	/*
	mergeSort(test);
	for (int i = 0; i < test.size(); i++)
	{
		cout << test[i] << ' ';
	}
	while (1);
	*/

	int n = 1000000;
	vector<int>randomVec = getRandomVector(n);

	vector<int>oneVec(n, 1);


	cout << "1000000随机数测试：" << endl;
	testQuickSort(randomVec);

	cout << "1000000个一测试：" << endl;
	testQuickSort(oneVec);

	
	int N[] = { 10000, 5000, 1000 };
	
	int X[] = { 50, 60, 70, 80, 90, 100 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{

			vector<int>tmp = getVector(N[i], X[j]);
			cout << "N:" << N[i] << " " << "X:" << X[j] << " 测试" << endl;
			
			testQuickSort(tmp);

		}
	}
	while (1);
	return 0;
}

void testQuickSort(vector<int>&arr)
{
	clock_t start, finish;
	double totaltime;
	start = clock();

	quickSort(arr, 0, arr.size() - 1);

	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC*1000.0;
	cout << "运行时间为" << totaltime << "毫秒！" << endl<<endl;
}