
int partition(int *A, int lo, int hi)
{
    int i = lo, j = hi + 1;
    while (true)
    {
        while (++i) if (i == hi || !(A[i] < A[lo])) break;
        while (--j) if (j == lo || !(A[lo] < A[j])) break;
        if (!(i < j))
            break;
        swap(A, i, j);
    }
    swap (A, lo, j);
    return j;
}

int select(int* A, int N, int K)
{
    int lo = 0;
    int hi = N - 1;
    while (lo < hi)
    {
        int mid = partition(A, lo, hi);
        if (K == mid)
            return K;
        else if (K < mid)
            hi = mid - 1;
        else 
            lo = mid + 1;
    }
    return K;
}