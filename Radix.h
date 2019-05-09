
#define MAX_CELL 20

struct Bucket
{
	T cell[MAX_CELL];
	int count;
};

void RadixSort(T* first, T* last)
{
	Bucket b[10];
	int radix = 1;
 	while (radix <= 100)
	{
		for (int i = 0; i < 10; ++i)
		{
			b[i].count = 0;
		}

		for (T* i = first; i != last; ++i)
		{
			int j = (*i / radix) % 10;
			b[j].cell[b[j].count] = *i;
			b[j].count += 1;
		}
	
		int k = 0;
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < b[i].count; ++j)
			{
				*(first + k) = b[i].cell[j];
				k++;
			}
		}

		radix *= 10;
	}


}