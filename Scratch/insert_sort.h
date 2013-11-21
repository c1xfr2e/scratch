
void is_noguard(int* p, int n)
{
    for (int i = 1; i < n; ++i)
    {
        int temp = p[i];
        if (temp < p[0])
        {
            memcpy(p + 1, p, i*sizeof(int));
            p[0] = temp;
        }
        else
        {
            int j = i - 1;
            while (temp < p[j])
            {
                p[j + 1] = p[j];
                --j;
            }
            p[j + 1] = temp;
        }
    }
}

void is(int *p, int n)
{
    for (int i = 1; i < n; ++i)
    {
        int temp = p[i];
        int j = i - 1;
        while (j >= 0 && p[j] > temp)
        {
            p[j + 1] = p[j];
            --j;
        }
        p[j + 1] = temp;
    }
}

void is_ptr(int *first, int *last)
{
    for (int* p = first + 1; p < last; ++p)
    {
        int temp = *p;
        int* next = p;
        int* last = next;
        --next;
        while (next >= first && temp < *next)
        {
            *last = *next;
            last = next;
            --next;
        }
        *last = temp;
    }
}

void linear_insert(int* p, int pos, int inc = 1)
{
    int temp = p[pos];
    int j = pos - inc;
    while (j >= 0 && p[j] > temp)
    {
        p[j + inc] = p[j];
        j -= inc;
    }
    p[j + inc] = temp;
}

void is_inc(int* p, int n, int inc)
{
    for (int i = inc; i < n; i += 1)
    {
        int temp = p[i];
        int j = i - inc;
        while (j >= 0 && p[j] > temp)
        {
            p[j + inc] = p[j];
            j -= inc;
        }
        p[j + inc] = temp;
    }
}

void insert_sort_2(T* first, T* last)
{
    T* p1 = first;
    ++p1;
    for (; p1 != last; ++p1)
    {
        T* p2 = p1;
        T* prev = p2;
        --prev;
        while (p2 != first && *p2 < *prev)
        {
            swap(p2, prev);
            p2 = prev;
            --prev;
        }   
    }
}