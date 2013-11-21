
T midian3(T& a, T& b, T& c)
{
	if (a < b)
	{
		if (c < a)
		{
			return a;
		}
		else if (b < c)
		{
			return b;
		}
		else
		{
			return c;
		}
	}
	else if (a < c)
	{
		return a;
	}
	else if (c < b)
	{
		return b;
	}
	else 
	{
		return c;
	}
}

int partition_unguard_1(T* p, int left, int right, T pivot)
{
	int lo = left - 1, hi = right + 1;
	while (true)
	{
		while (p[++lo] < pivot)
		{
		}
		while (p[--hi] > pivot)
		{
		}
		if (lo < hi)
		{
			swap(p, lo, hi);
		}
		else
		{
			break;
		}
	}
	return lo;
}

void quick_sort_1(T* p, int first, int last)
{
	if (last - first < 1)
	{
		return;
	}
	int mid = partition_unguard_1(p, first, last, midian3(p[first], p[first + (last - first + 1)/2], p[last]));
	quick_sort_1(p, first, mid - 1);
	quick_sort_1(p, mid, last);
}

int partition_2(T* p, int left, int right)
{
	int lo = left, hi = right + 1;
	while (true)
	{
		while (p[++lo] < p[left])
		{
			if (lo >= right)
			{
				break;
			}
		}
		while (p[--hi] > p[left])
		{
			if (hi <= left)
			{
				break;
			}
		}
		if (lo < hi)
		{
			swap(p, lo, hi);
		}
		else
		{
			break;
		}
	}
	swap(p, left, hi);
	return hi;
}

void quick_sort_2_impl(T* p, int left, int right)
{
	if (left >= right)
		return;
	int mid = partition_2(p, left, right);
	quick_sort_2_impl(p, left, mid - 1);
	quick_sort_2_impl(p, mid + 1, right);
}

void quick_sort_2(T* p, int n)
{
	quick_sort_2_impl(p, 0, n - 1);
}

int ITA_partition(T* A, int q, int r)
{
    int v = A[r];
    int i = q;
    for (int j = q; j < r; j++)
    {
        if (A[j] < v)
        {
            swap(A, i, j);
            ++i;
        }
    }
    swap(A, i, r);
    return i;
}