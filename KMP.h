#pragma once

int kmp_full_dfa(const char* str, const char* pat)
{
	int dfa[20][3] = {0};
	dfa[0][pat[0] - 'A'] = 1;
	int M = strlen(pat);
	int X = 0;
	for (int i = 1; i < M; i++)
	{
		for (int j = 0; j < 3; j++)
			dfa[i][j] = dfa[X][j];
		dfa[i][pat[i] - 'A'] = i + 1;
		X = dfa[X][pat[i] - 'A'];
	}

	int str_len = strlen(str);
	int i = 0, j = 0;
	for ( ; i < str_len && j < M; i++)
		j = dfa[j][str[i] - 'A'];
	if (j == M)
		return i - M;
	else 
		return -1;
}

int kmp_mismatch_transition(const char* txt, const char* pat)
{
	int M = strlen(pat);
	int* next = new int[M];
	memset(next, 0, M*sizeof(int));
	next[0] = -1;
	int X = -1;
	for (int i = 1; i < M; ++i)
	{
		while (!(X == -1 || pat[i - 1] == pat[X]))
			X = next[X];
		X++;
		if (pat[i] == pat[X])
			next[i] = next[X];
		else
			next[i] = X;
	}

	int N = strlen(txt);
	int i = 0, j = 0;
	for ( ; i < N && j < M; i++)
	{
		while (j != -1 && txt[i] != pat[j])
			j = next[j];
		j++;
	}

	delete[] next;

	if (j == M)
		return i - M;
	else
		return -1;
}

int Boyer_Moore(const char* txt, const char* pat)
{
	int M = strlen(pat);
	int R = 128;
	int *right = new int[R];
	for (int i = 0; i < R; i++)
		right[i] = -1;
	for (int i = 0; i < M; i++)
		right[pat[i]] = i;
	
	int N = strlen(txt);
	int i = 0, j = 0, k = 0;
	for ( ; i <= N - M; i += k)
	{
		for (j = M - 1; j >= 0; j--)
		{
			if (txt[i + j] != pat[j])
			{
				k = j - right[txt[i + j]];
				if (k < 1)
					k = 1;
				break;
			}
		}
		if (j == -1)
			return i;
	}
	return -1;
}