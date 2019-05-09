
int gcd(int m, int n)
{
    int r;
    while (n != 0)
    {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}

void rotate(T* A, int begin, int new_begin, int last)
{
    int n = last - begin;
    int d = new_begin - begin;
    int c = gcd(n, d);
    for (int i = 0; i < c; i++)
    {
        T tmp = A[i];
        int prev = i;
        int next = prev + d;
        while (next != i)
        {
            A[prev] = A[next];
            prev = next;
            next = (next + d) % n;
        }
        A[prev] = tmp;
    }
}

void rotate_recursive(T* A, int begin, int new_begin, int last)
{
    if (!((new_begin > begin) && (new_begin < last)))
        return;
    int i = begin;
    int j = new_begin;
    while (i != new_begin && j != last)
        swap(A, i++, j++);
    if (i == new_begin)
        rotate_recursive(A, i, j, last);
    else
        rotate_recursive(A, i, new_begin, j);
}
