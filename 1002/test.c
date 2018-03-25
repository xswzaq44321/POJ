#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isdigit(int n){
	if(n >= '0' && n <= '9') return 1;
	else return 0;
}

int compare(const void *a, const void *b){
	return (*(int*)a - *(int*)b);
}

int transform(char *data){
	int bar = 0;
	for(int i = 0; data[i] != '\0'; i++){
		if(isdigit(data[i])){
			bar *= 10;
			bar += data[i] - '0';
		}else{
			if(data[i] <= 'P' && data[i] >= 'A'){
				bar *= 10;
				bar += (data[i] - 'A') / 3 + 2;
			}else if(data[i] <= 'Y' && data[i] >= 'R'){
				bar *= 10;
				bar += (data[i] - 'Q') / 3 + 7;
			}
		}
	}
	return bar;
}

int main(){
	int N;
	int number[100000];
	memset(number, 0, 100000);
	char temp[100];
	int count = 1, duplicate = 0;

	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%s", temp);
		number[i] = transform(temp);
	}
	qsort(number, N, sizeof(int), compare);

	for(int i = 0; i < N; i++, count = 1){
		for(; number[i] == number[i + 1]; i++, count++);
		if(count > 1){
			duplicate++;
			printf("%03d-%04d %d\n", number[i] / 10000, number[i] % 10000, count);
		}
	}
	if(!duplicate){
		printf("No duplicates.\n");
	}
}
