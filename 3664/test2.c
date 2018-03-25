#include <stdio.h>
#include <string.h>
#define SIZE 51000

int A[SIZE], B[SIZE];
int voteIndex[SIZE];// refer to the address of votes' data
//anyone who wants to access A's data will need to use voteIndex as a pipeline
int temp[SIZE];
int N, K;

void quickDivide(int low, int high){
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
	for(int n = low; n <= high; n++){
		voteIndex[n] = temp[n];
	}
//	memcpy(&voteIndex[low], &temp[low], sizeof(int) * (high - low + 1));

	for(int n = 0; n < N; n++){
		fprintf(stderr, "%d %d\r\n", A[voteIndex[n]], voteIndex[n]);
	}
	fprintf(stderr, "===============\r\n");

	if(high - low > 1){
		quickDivide(low, i - 1);
		quickDivide(i + 1, high);
	}
}

int main(){
	int max = 0, maxIndex;

	scanf(" %d %d", &N, &K);
	for(int i = 0; i < N; i++){
		scanf(" %d %d", &A[i], &B[i]);
	}
	for(int i = 0; i < N; i++){
		voteIndex[i] = i;
	}

	quickDivide(0, N-1);
}
