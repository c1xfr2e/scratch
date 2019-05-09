
int unique(T* p, int n)
{
    int first = 0;
    int next = 1;
    while (next < n)
    {   
        if (p[first] == p[next])
        {
            int dest = next;
            for (int src = next + 1; src < n; ++src)
            {
                if (p[src] != p[first])
                {
                    p[dest++] = p[src];
                }
            }
            n = dest;
        }
        first = next;
        ++next;
    }
    return n;
}