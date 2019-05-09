
#include "common.h"

void bs(int *p, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        bool has_swap = false;
        for (int j = n - 1; j > i; --j)
        {
            if (p[j - 1] > p[j])
            {
                int temp = p[j - 1];
                p[j - 1] = p[j];
                p[j] = temp;
                has_swap = true;
            }
        }
        if (!has_swap)
        {
            break;
        }
    }
}

void bs_2(int *p, int n)
{
    for (int i = n - 1; i > 0; --i)
    {
        bool swap = false;
        for (int j = 0; j < i; ++j)
        {
            if (p[j] > p[j + 1])
            {
                int temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
                swap = true;
            }
        }
        if (!swap)
        {
            break;
        }
    }
}

void bs_3(T* start, T* end)
{
    for (--end; end > start; --end)
    {
        for (T* p = start; p != end; ++p)
        {
            T* next = p;
            ++next;
            if (*p > *next)
            {
                swap(p, next);
            }
        }
    }
}















