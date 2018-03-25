#include <stdio.h>
#include <string.h>
#define SIZE 51000

int A[SIZE], B[SIZE];
int voteIndex[SIZE];// refer to the address of votes' data
int temp[SIZE];

void quickDivide(int low, int high, int watershed){
	int mid = (low + high) / 2;
	int i = low, j = high, pivot = A[voteIndex[mid]];

	for(int n = low; n <= high; n++){ //process the data from low to high, but skip the pivot
		if(n == mid) continue;
		if(A[voteIndex[n]] < pivot){
			temp[i++] = voteIndex[n];
		}else{
			temp[j--] = voteIndex[n];
		}
	}
	temp[i] = voteIndex[mid];
	memcpy(&voteIndex[low], &temp[low], sizeof(int) * (high - low + 1));

	if(i > watershed){
		quickDivide(low, i - 1, watershed);
	}else if(i < watershed){
		quickDivide(i + 1, high, watershed);
	}else{
		return;
	}
}

int main(){
	int N, K;
	int watershed;
	int max = 0, maxIndex;

	scanf(" %d %d", &N, &K);
	for(int i = 0; i < N; i++){
		scanf(" %d %d", &A[i], &B[i]);
	}
	for(int i = 0; i < N; i++){
		voteIndex[i] = i;
	}

	watershed = N - K;
	quickDivide(0, N-1, watershed);

#ifdef DEBUG
	for(int i = 0; i < N; i++){
		fprintf(stderr, "%d\n", A[voteIndex[i]]);
	}
#endif

	for(int i = watershed; i < N; i++){
		if(B[voteIndex[i]] > max){
			max = B[voteIndex[i]];
			maxIndex = voteIndex[i];
		}
	}
	printf("%d", maxIndex + 1);
}
