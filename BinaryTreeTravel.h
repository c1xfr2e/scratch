
int g_array[3];

void Travel(int k)
{
    if (k == 3)
    {
        for (int i = 0; i < k; ++i)
        {
            printf("%d ", g_array[i]);
        }
        printf("\n");
        return;
    }
    g_array[k] = 0;
    Travel(k + 1);
    g_array[k] = 1;
    Travel(k + 1);
}