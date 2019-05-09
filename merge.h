
void merge(T* src, T* aux, int first, int mid, int last)
{
	for (int i = first; i < last; ++i)
	{
		aux[i] = src[i];
	}

    int i1 = first, i2 = mid;
    while (i1 < mid && i2 < last)
    {
        if (aux[i1] < aux[i2])
        {
            src[first++] = aux[i1++];
        }
        else
        {
            src[first++] = aux[i2++];
        }
    }
    while (i1 < mid)
    {
        src[first++] = aux[i1++];
    }
    while (i2 < last)
    {
        src[first++] = aux[i2++];
    }
}

void ms_impl(T* src, T* aux, int first, int last)
{   
    if (last - first > 1)
    {
        int mid = first + (last - first) / 2;
        ms_impl(src, aux, first, mid);
        ms_impl(src, aux, mid, last);
        merge(src, aux, first, mid, last);
    }
}

void merge_sort(T* p, int n)
{
    T* aux = new T[n];
    ms_impl(p, aux, 0, n);
    delete[] aux;
}

void merge_sort_no_recursion(T* p, int n)
{
    int* aux = new T[n];
    mem_cpy(aux, p, sizeof(T)*n);
    for (int size = 1; size < n; size *= 2)
    {
        for (int lo = 0; lo < n - size; lo += size*2)
        {
            int mid = lo + size;
            int hi = (lo + size * 2) > n ? n : (lo + size * 2);
            merge(p, aux, lo, mid, hi);
        }
    }
}