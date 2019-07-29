#include<vector>
#include<iostream>
#include<random>
#include <time.h> 

using namespace std;
void quickSort(vector<int> &arr, int left, int right);
void exchange(int &a, int &b);
void insertSort(vector<int> &arr);
void bubbleSort(vector<int>&arr);

void selectSort(vector<int>&arr);
void heapSort(vector<int>&arr);
void mergeSort(vector<int>&arr);
vector<int> getRandomVector(int n);
vector<int> getVector(int n, int x);