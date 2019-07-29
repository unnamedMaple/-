#include"Header.h"

vector<int> getRandomVector(int n)
{
	vector<int>ret(n, 0);
	srand((unsigned)time(NULL));

	for (int i = 0; i < n; i++)
	{
		ret[i] = rand();
	}
	return ret;
}

vector<int> getVector(int n, int x)
{
	vector<int>ret(n, 1);
	float percent = (float)x / 100.0;
	int index = percent *n;
	srand((unsigned)time(NULL));
	for (; index < n; index++)
	{
		ret[index] = rand();
	}
	return ret;
}

