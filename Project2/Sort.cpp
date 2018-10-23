#include "Sort.h"



Sort::Sort()
{
}

void Sort::Bubble_sort(int* a, int n)
{
	int flag;
	int temp;
	for (int i = 0,flag=1; i < n&&flag==1; i++)
	{
		flag = 0;
		for (int j = 1; j < n - i; j++)
		{
			if (a[j] < a[j - 1])
			{
				//exchange(a[j],a[j-1])
				temp = a[j];
				a[j] = a[j-1];
				a[j - 1] = temp;
			}
			flag = 1;
		}
	}

}
void Sort::Select_sort(int* a, int n)
{
	int min;
	int temp;
	for (int i = 0; i < n; i++)
	{
		min = i;
		for (int j = i; j < n; j++)
		{
			if (a[min] > a[j])
				min = j ;

		}
		//exchange(a[min],a[i])
		temp = a[min];
		a[min] = a[i];
		a[i] = temp;
	}

}
void Sort::Insert_sort(int* a, int n)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (a[j] < a[j - 1])
			{
				//exchange(a[j],a[j-1])
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
			else
			{
				break;
			}
		}

	}


}
void Sort::Shell_sort(int* a, int n)
{
	int temp;
	int gap = n;
	while (gap>1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < n; i++)
		{
			
			if (a[i] < a[i - gap])
			{
				//exchange(a[i],a[i-gap])
				int j = i - gap;
				while (j >= 0 && a[j] > a[j+gap])
				{
					temp = a[j];
					a[j] = a[j+gap];
					a[j+gap] = temp;
					j -= gap;
				}

			}
		}
	}

}

int Sort::partition(int* a, int lo, int hi)
{
	int v = a[lo];
	int i = lo;
	int j = hi;
	int temp;
	while (true)
	{
		while (!(a[--j] < v)) if (j <= lo) break;
		while (!(a[++i] > v)) if (i >= hi) break;
		if (i >= j) break;
		//exchange(a[i],a[j])
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;

	}

	//exchange(a[j],a[lo])
	temp = a[j];
	a[j] = a[lo];
	a[lo] = temp;

	return j;
}
void Sort::Quick_sort(int* a, int lo, int hi)
{
	if (lo >= hi) return;
	int mid = partition(a, lo, hi);
	Quick_sort(a, lo, mid-1);
	Quick_sort(a, mid + 1, hi);

}
void Sort::Merge_sort(int* a, int n)
{
	int* aux = new int[n]; //��������
	Merge_sort1(a, aux, 0, n - 1);

}
void Sort::Merge_sort1(int* a, int* aux, int lo, int hi)
{
	if (hi <= lo) return;
	int mid = lo+ (hi-lo) / 2;
	Merge_sort1(a, aux, lo, mid);
	Merge_sort1(a, aux, mid + 1, hi);
	Merge(a, aux, lo, mid, hi);

}
void Sort::Merge(int*a, int* aux, int lo, int mid, int hi)
{
	for (int i = lo; i <= hi; i++)
	{
		aux[i] = a[i];
		std::cout << aux[i]<<",";
	}
	std::cout << std::endl;
	int i = lo;
	int j = mid + 1;
	for(int k=lo;k<=hi;k++)
	{
		if (i > mid)  a[k] = aux[j++];
		else if (j > hi) a[k] = aux[i++];
		else if (aux[i] > aux[j]) a[k] = aux[j++];
		else a[k] = aux[i++];
	}

}
void Sort::heapAdjust(int* a, int k, int n)
{
	int temp;	
		while (2 * k + 1 <= n - 1)    //ӵ�����ӽ��
		{
			int i = 2 * k + 1;
			if (i <= n - 2 && a[i] < a[i + 1])  //���ӽڵ�������ӽڵ��ֵ
				i++;
			if (a[i] > a[k])    //�����ӽڵ���ڸ��ڵ�
			{
				//exchange
				temp = a[i];
				a[i] = a[k];
				a[k] = temp;

				k = i; //�������� ��������Ľ��
			}
			//���ڵ�������ӽڵ㶼������������Ҫ����
			else {
				break;
			}
		}
}
void Sort::Heap_Sort(int* a, int n)
{
	int temp;
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		//�Ӻ���ǰ�����ÿһ����Ҷ�ڵ���е���
		
		heapAdjust(a, i, n);
		
	}//�󶥶ѹ��� a[0]Ϊ�����
	
	
	for (int i = n - 1; i > 0; --i)
	{
		//exchange(a[0],a[i])
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		//Ŀǰ���Ԫ�ط�����ȷλ��
		heapAdjust(a, 0, i);//�Ա�С�Ķѽ��д󶥶ѹ���
	}

}
Sort::~Sort()
{
}
