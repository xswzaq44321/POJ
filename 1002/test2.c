#include <stdio.h>
#include <ctype.h>

int transform(char *data){
	int bar = 0;
	for(int i = 0; i < 16 && data[i] != '\0'; i++){
		bar *= 10;
		if(isdigit(data[i])){
			bar += data[i] - '0';
		}else{
			if(data[i] <= 'P' && data[i] >= 'A'){
				bar += (data[i] - 'A') / 3 + 2;
			}else if(data[i] <= 'Y' && data[i] >= 'R'){
				bar += (data[i] - 'Q') / 3 + 7;
			}else{ // if it is '-'
				bar /= 10; // make it back
				continue;
			}
		}
	}
	return bar;
}

int main(){
	char arr[16];
	scanf("%s", arr);
	printf("%d", transform(arr));
}
