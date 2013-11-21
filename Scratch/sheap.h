
#pragma once

typedef int T;

void sd(T* p, int hole, int n)
{
    T val = p[hole];
    int child = hole * 2 + 2;
    while (child < n)
    {
        if (p[child - 1] > p[child])
        {
            child -= 1;
        }
        if (p[child] > val)
        {
            p[hole] = p[child];
            hole = child;
            child = hole * 2 + 2;
        }
        else
        {
            break;
        }
    }
    if (child == n && p[child - 1] > val)
    {
        p[hole] = p[child - 1];
        hole = child - 1;
    }
    p[hole] = val;
}

void to_make_heap(T* p, int n)
{
    for (int i = (n - 2) / 2; i >= 0; --i)
    {
        sd(p, i, n);
    }
}

T pop_h(T* p, int n)
{
    T ret = p[0];
    p[0] = p[n - 1];
    sd(p, 0, n - 1);
    return ret;
}

void hs(T* p, int n)
{
    to_make_heap(p, n);
    for (int i = n - 1; i > 0; --i)
    {
        p[i] = pop_h(p, i + 1);
    }
}