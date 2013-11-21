
void ss(int* p, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (p[j] < p[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = p[min];
            p[min] = p[i];
            p[i] = temp;
        }
    }
}