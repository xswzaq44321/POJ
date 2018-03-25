#include <stdio.h>
#include <string.h>
#define MAX 40000

int main(){
	int N, M;
	int W[MAX] = {0}, D[MAX] = {0}, dp[40000] = {0};

	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++){
		scanf("%d %d", &W[i], &D[i]);
	}

	for(int i = 0; i < N; i++){
		for(int j = M; j >= W[i]; j--){
			if(dp[j - W[i]] + D[i] > dp[j]){
				dp[j] = dp[j - W[i]] + D[i];
			}
		}
	}

	printf("%d\n", dp[M]);
}
