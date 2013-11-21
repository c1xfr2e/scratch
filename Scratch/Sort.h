
#include <stdlib.h>

typedef int T;

void swap1(T* a, T* b)
{
	T t = *a;
	*a = *b;
	*b = t;
}

void BubbleSort(T* first, T* last)
{
	--last;
	for (T* p1 = first; p1 != last; ++p1)
	{
		T* p2 = last;
		T* prev = p2;
		--prev;
		while (p2 != p1)
		{
			if (*p2 < *prev)
			{
				swap1(p2, prev);
			}
			p2 = prev;
			--prev;
		}
	}
}

void SelectionSort(T* first, T* last)
{
	T* end = last;
	--end;
	for (T* p1 = first; p1 != end; ++p1)
	{
		T* min = p1;
		T* p2 = p1;
		for (++p2; p2 != last; ++p2)
		{
			if (*p2 < *min)
			{
				min = p2;
			}
		}
		swap1(p1, min);
	}
}

void InsertSort(T* first, T* last)
{
	T* p1 = first;
	for (++p1; p1 != last; ++p1)
	{
		T tmp = *p1;
		T* p2 = p1;
		T* prev = p2;
		--prev;
		while (p2 != first && tmp < *prev)
		{
			*p2 = *prev;
			p2 = prev;
			--prev;
		}
		*p2 = tmp;
	}
}

T* Quicksort_Partition(T* first, T* last)
{
	T* lo = first;
	T* hi = last;
	while (true)
	{
		while (lo < last && *++lo < *first) {}
		while (hi > first && *--hi > *first) {}
		if (!(lo < hi))
		{
			break;
		}
		swap1(lo, hi);
	}
	swap1(first, hi);
	return hi;
}

void QuickSort(T* first, T* last)
{
	if (last - first < 2)
	{
		return;
	}

	T* mid = Quicksort_Partition(first, last);
	QuickSort(first, mid);
	QuickSort(mid + 1, last);
}

// merge [first, mid) and [mid, last)
void Merge(T* first, T* mid, T* last, T* aux)
{
	T* p = aux;
	for (T* i = first; i != last; ++i)
		*p++ = *i;
	T* aux_mid = aux + (mid - first);
	T* aux_last = aux + (last - first);
	T* i = aux;
	T* j = aux + (mid - first);
	for (T* k = first; k != last; ++k)
	{
		if (i >= aux_mid)
			*k = *j++;
		else if (j >= aux_last)
			*k = *i++;
		else if (*i < *j)
			*k = *i++;
		else
			*k = *j++;
	}
}

void MergeSort_Impl(T* first, T* last, T* aux)
{
	if (last - first < 2)
	{
		return;
	}
	
	T* mid = first + (last - first) / 2;
	MergeSort_Impl(first, mid, aux);
	MergeSort_Impl(mid, last, aux);
	Merge(first, mid, last, aux);
}

void MergeSort(T* first, T* last)
{
	T* b = (T*)malloc(sizeof(T) * (last - first));
	MergeSort_Impl(first, last, b);
}

void MergeSort2(T* p, int n)
{
	T* aux = (T*)malloc(n * sizeof(T));
	for (int s = 1; s < n; s *= 2)
	{
		for (int i = 0; i < n - s; i += s*2)
		{
			int k = i + s*2;
			if (k > n)
				k = n;
			Merge(p + i, p + i + s, p + k, aux);
		}
	}
}

template<int len>
T* part(T* first, T* last, T (&a)[len])
{
	T* i = first;
	T* j = last;
	--last;
	while (1)
	{
		while (i < last && *++i < *first) {}
		while (j > first && *--j > *first) {}
		if (!(i < j))
			break;
		swap1(i, j);
	}
	swap1(first, j); 
	return j;
}

template<int len>
T getk(T* first, T* last, int k, T (&a)[len])
{
	T* m = part(first, last, a);
	int d = (int)(m - first);
	if (d == k)
		return *m;
	else if (d > k)
		return getk(first, m, k, a);
	else 
		return getk(m + 1, last, k - d - 1, a);
}