#include "iostream"
#include "Sort.h"
using namespace std;
void main()
{
	int data[5] = { 3,2,6,5,4 };
	//int data[5] = { 4,2,5,1,3 };
	for (int i = 0; i < 5; i++)
	{
		cout << data[i];
	}
	cout << endl;
	Sort* sort = new Sort();
	//sort->Select_sort(data, 5);
	//sort->Bubble_sort(data, 5);
	//sort->Insert_sort(data, 5);
	//sort->Shell_sort(data, 5);
	//sort->Quick_sort(data, 0, 5);
	//sort->Merge_sort(data, 5);
	sort->Heap_Sort(data, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << data[i];
	}

}