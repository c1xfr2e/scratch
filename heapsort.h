
#pragma once

#include "common.h"

void sd(T p[], int hole, int n)
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

T pop_h(T p[], int n)
{
    T ret = p[0];
    p[0] = p[n - 1];
    sd(p, 0, n - 1);
    return ret;
}

template<int N>
void sink(T (&p)[N], int hole, int n)
{
    int temp = p[hole];
    for (int child = hole * 2 + 1; child < n; child = child * 2 + 1)
    {
        if (child < n - 1 && p[child] < p[child + 1])
        {
            child++;
        }
        if (temp >= p[child])
        {
            break;
        }
        p[hole] = p[child];
        hole = child;
    }
    p[hole] = temp;
}

template<int N>
void to_make_heap(T (&p)[N], int n)
{
    for (int i = (n - 2) / 2; i >= 0; --i)
    {
        sink(p, i, n);
    }
}

template<int N>
void heap_sort(T (&p)[N], int n)
{
    to_make_heap(p, n);
    for (int i = n - 1; i > 0; --i)
    {
        swap(p, 0, i);
        sink(p, 0, i);
    }
}

void swim(T* p, int hole)
{
    while (hole > 0)
    {
        int up = (hole - 1) / 2;
        if (p[hole] > p[up])
        {
            swap(p, hole, up);
            hole = up;
        }
        else
        {
            break;
        }
    }
}

void sink2(T* p, int hole, int length)
{
    int child = hole * 2 + 1;
    while (child < length)
    {
        if (child + 1 < length && p[child] < p[child + 1])
        {
            child++;
        }
        if (!(p[hole] < p[child]))
        {
            break;
        }
        swap(p, hole, child);
        hole = child;
        child = 2 * hole + 1;
    }
}