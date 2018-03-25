#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv){
	if(argc != 2){
		printf("Error! Usage : %s\b\b [N]", __FILE__);
		exit(1);
	}
	int N = atoi(argv[1]);
	long long int number = 1;
	srand(time(NULL));

	printf("%d\n", N);
	for(int i = 0; i < N; i++, number = 1){
		number = rand();
		printf("%lld\n", number % (1000000000));
	}
}
