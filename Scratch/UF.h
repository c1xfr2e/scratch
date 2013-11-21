#pragma once

class UF
{
public:
    UF(int N)
    {
        count = N;
        id = new int[N];
        sz = new int[N];
        for (int i = 0; i < N; ++i)
        {
            id[i] = i;
            sz[i] = 1;
        }
    }
    ~UF()
    {
        delete[] id;
        delete[] sz;
    }

    int find(int p)
    {
        while (id[p] != p)
            p = id[p];
        return p;
    }

    bool query(int p, int q)
    {
        return (find(p) == find(q));
    }

    void link(int p, int q)
    {
        p = find(p);
        q = find(q);
        if (p == q)
            return;
        if (sz[p] < sz[q])
        {
            id[p] = q;
            sz[q] += sz[p];
        }
        else
        {
            id[q] = p;
            sz[p] += sz[q];
        }
        count--;
    }

private:
    int* id;
    int* sz;
    int count;
};