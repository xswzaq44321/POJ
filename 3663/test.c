#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
	return (*(int*)a - *(int*)b);
}

int main(){
	int N, S;
	int L[20000];
	int count = 0;
	
	scanf("%d %d", &N, &S);
	for(int i = 0; i < N; i++){
		scanf("%d", &L[i]);
	}

	qsort(L, N, sizeof(int), compare);

	for(int i = N - 1; i >= 0; i--){
		for(int j = 0; j < i; j++){
			if(L[i] + L[j] > S){
				break;
			}
			count++;
		}
	}
	printf("%d", count);
}
