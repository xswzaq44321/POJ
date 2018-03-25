#include<stdio.h>

void Merge(long long int list [], int low, int high, int MAX_SIZE)
{ long long int combined[MAX_SIZE];
	int k = 0, mid = (low + high) / 2;
	int i = low, j = mid + 1;

	while (i <= mid && j <= high)
	{ if (list[i] < list[j])
		combined[k++] = list[i++];
		else combined[k++] = list[j++];
	}

	while (i <= mid)
		combined[k++] = list[i++];

	while (j <= high)
		combined[k++] = list[j++];

	for (i = low, j = 0; i <= high; i++, j++)
		list[i] = combined[j];
}


	void Mergesort(long long int list[], int low, int high, int number)
{ if (high > low)
	{ Mergesort(list, low, (low + high) / 2, number);
		Mergesort(list, (low + high) / 2 + 1, high, number);
		Merge(list, low, high, number);
	}
}

int main()
{
	int x;
	long long int num;
	long long int count=0;

	int N;
	scanf("%d",&N);

	long long int a[N];

	//The location of each cow (in the range 0...1,000,000,000).
	//所以用long long int

	for(x=0; x<N; x++)
	{
		scanf("%lld",&num);
		a[x]=num;
	}

	Mergesort(a,0,N-1,N);
#ifdef DEBUG
	for(int i = 0; i < N; i++){
		fprintf(stderr, "%lld\n", a[i]);
	}
#endif


	for(x=0;x+1<N;x++)
		count=count+(a[x+1]-a[x])*(N-x-1)*(x+1);

	//因為已經排序，兩個相鄰元素的距離會出現(N-x-1)(x+1)次(先只看單向)

	count=count*2;

	printf("%lld",count);

	return 0;
}
