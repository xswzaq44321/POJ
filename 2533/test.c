#include <stdio.h>
#define SIZE 1100
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int num[SIZE];
int lis[SIZE];

int findLis(int n){
	for(int k = 0; k < n; ++k){
		lis[k] = 1;
		for(int i = 0; i < k; ++i){
			if(num[i] < num[k]){
				lis[k] = MAX(lis[k], lis[i] + 1);
			}
		}
	}
}

int main(){
	int N, max = 0;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", &num[i]);
	}

	findLis(N);

	for(int i = 0; i < N; ++i){
		max = MAX(lis[i], max);
	}
	printf("%d", max);
}
