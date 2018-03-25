#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
	return (*(int*)a - *(int*)b);
}

int main(){
	int N;
	int cow[10100];
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf(" %d", &cow[i]);
	}

	qsort(cow, N, sizeof(int), compare);

	printf("%d", cow[N/2]);
}
