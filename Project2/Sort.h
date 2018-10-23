#pragma once
#include "iostream"
class Sort
{
public:
	Sort();
	void Bubble_sort(int* a, int n);
	void Select_sort(int* a, int n);
	void Insert_sort(int* a, int n);
	void Shell_sort(int* a, int n);

	int partition(int* a, int lo, int hi);
	void Quick_sort(int* a, int lo, int hi);

	void Merge_sort(int* a, int n);
	void Merge_sort1(int* a,int* aux, int lo, int hi);
	void Merge(int*a, int* aux, int lo, int mid,int hi);

	void heapAdjust(int* a,int k, int n);
	void Heap_Sort(int* a, int n);
	~Sort();
};

