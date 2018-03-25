#include <stdio.h>
#include <stdlib.h>

typedef struct PHONE_NUMBER{
	int number;
	int count;
	struct PHONE_NUMBER *next;
}PhoneNumber;

int isdigit(int n){
	if(n >= '0' && n <= '9') return 1;
	else return 0;
}

PhoneNumber *insertNumber(PhoneNumber *head, int data){ // insert a phone number as whether a new node or count
	PhoneNumber *bar = head;
	if(bar->number == data){ //same as first one
		bar->count++;
		return head;
	}else if(bar->number > data){ // smaller than first one
		PhoneNumber *temp = malloc(sizeof(PhoneNumber));
		temp->number = data;
		temp->count = 1;
		temp->next = head;
		return temp; // return temp as new head
	}else{
		for(; bar->next != NULL && bar->next->number < data; bar = bar->next);
	}

	if(bar->next != NULL && bar->next->number == data){
		bar->next->count++;
		return head;
	}else{
		PhoneNumber *temp = malloc(sizeof(PhoneNumber));
		temp->number = data;
		temp->count = 1;
		temp->next = bar->next;
		bar->next = temp;
		return head;
	}
}

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
	char temp[100];
	int N, number, duplicate = 0;
	PhoneNumber *head = malloc(sizeof(PhoneNumber));
	scanf("%d", &N);

	//initialize linked list
	scanf("%s", temp);
	number = transform(temp);
	head->number = number;
	head->count = 1;
	head->next = NULL;

	for(int i = 0; i < N - 1; i++){
		scanf("%s", temp);
		number = transform(temp);
		head = insertNumber(head, number);
	}

	for(PhoneNumber *i = head; i != NULL; i = i->next){
		if(i->count < 2) continue;
		int number1, number2, numberCount;
		number1 = i->number / 10000;
		number2 = i->number % 10000;
		numberCount = i->count;
		printf("%03d-%04d %d\n", number1, number2, numberCount);
		duplicate++; // counts how many duplicate numbers;
	}
	if(!duplicate){
		printf("No duplicates.\n");
	}
}
