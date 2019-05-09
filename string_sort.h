#pragma once

void MSD(vector<string>& a, vector<string>& aux, int lo, int hi, size_t d)
{
	if (hi <= lo) return;

	int N = hi - lo + 1;
	int R = 256;
	vector<int> count(R + 1, 0);
	int d_length_index = 0;

	for (int i = lo; i <= hi; ++i)
	{
		if (d < a[i].length())
			count[a[i].at(d) + 1]++;
		else
			count[0]++;
	}
	for (int i = 1; i < R + 1; ++i)
		count[i] += count[i - 1];
	for (int i = lo; i <= hi; ++i)
	{
		if (d < a[i].length())
			aux[count[a[i].at(d)]++] = a[i];
		else
			aux[d_length_index++] = a[i];
	}
	for (int i = 0; i < N; ++i)
		a[lo + i] = aux[i];

	for (int i = 0; i < R; ++i)
		MSD(a, aux, lo + count[i], lo + count[i + 1] - 1, d + 1);
}

void LSD(vector<string>& a, int W)
{
	size_t N = a.size();
	size_t R = 256;
	vector<int> count(R + 1, 0);
	vector<string> aux(N);
	for (int d = W - 1; d >= 0; d--)
	{
		// reset count
		count.assign(R + 1, 0);
		// count element
		for (size_t i = 0; i < N; i++)
			count[a[i].at(d) + 1]++;
		// get index
		for (size_t i = 1; i < R + 1; i++)
			count[i] += count[i - 1];
		// distribute
		for (size_t i = 0; i < N; i++)
			aux[count[a[i].at(d)]++] = a[i];
		// restore
		for (size_t i = 0; i < N; i++)
			a[i] = aux[i];
	}
}
