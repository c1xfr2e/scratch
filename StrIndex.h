
#include <stdio.h>

int index(char *s, char *t)
{
    int ns = (int)strlen(s);
    int nt = (int)strlen(t);
    for (int i = 0; i <= ns - nt; ++i)
    {
        int k = i;
        int j = 0;
        while (j < nt)
        {
            if (s[j] != '\0' && s[k] == t[j])
            {
                ++k;
                ++j;
            }
            else
            {
                break;
            }
        }
        if (j == nt)
        {
            return k - j;
        }
    }

    return -1;
}

void get_next(const char *s, int *next)
{
    int j = -1;
    next[0] = j;
    int n = (int)strlen(s);
    for (int i = 1; i < n; ++i)
    {
        while (j != -1 && s[i - 1] != s[j])
            j = next[j];
        j++;
        if (s[i] == s[j])
            next[i] = next[j];
        else
            next[i] = j;
    }
}

int index_kmp(const char *s, const char *t)
{
    int next[255];
    get_next(t, next);
    int ns = (int)strlen(s), nt = (int)strlen(t);
    int i = 0, j = 0;
    while (i < ns && j < nt)
    {
        if (j == -1 || s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j == nt)
        return i - j;
    else
        return -1;
}
