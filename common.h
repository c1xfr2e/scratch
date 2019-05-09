#ifndef COMMON_H
#define COMMON_H

typedef int T;

inline void swap(T *p, int a, int b)
{
    T tmp = p[a];
    p[a] = p[b];
    p[b] = tmp;
}

inline void swap(T *p1, T *p2)
{
    T t = *p1;
    *p1 = *p2;
    *p2 = t;
}

#endif
