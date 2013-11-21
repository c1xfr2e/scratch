
void shell(int *p, int n)
{
    int inc = 4;
    while (inc > 0)
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

        inc = inc / 2;
    }
}