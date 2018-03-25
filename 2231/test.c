#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b){
	long long int m = (*(long long int*)a - *(long long int*)b);
	if(m < 0) return -1;
	if(m == 0) return 0;
	if(m > 0) return 1;
}

int main(){
	int N;
	long long int queue[10100];
	long long int A_0 = 0, B_0 = 0, sum = 0;
	long long int A_n, B_n;

	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf(" %lld", &queue[i]);
	}

	qsort(queue, N, sizeof(long long int), compare);
#ifdef DEBUG
	for(int i = 0; i < N; i++){
		fprintf(stderr, "%lld\n", queue[i]);
	}
#endif

	for(int i = 0; i < N; i++){
		B_0 += queue[i] - queue[0];
	}

	A_n = A_0, B_n = B_0;
	for(int i = 1; i <= N; i++){
		sum += (A_n + B_n);
		A_n += (long long int)(queue[i] - queue[i - 1]) * (i);
		B_n -= (long long int)(queue[i] - queue[i - 1]) * (N - i);
	}

	printf("%lld", sum);
}
