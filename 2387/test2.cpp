#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;

const int MAX_V = 1005;
const int MAX_E = 2010; 
const int INF = 0x7fffffff;
int d[MAX_V];//s到各的距离 
int n, T;//注意n 

int u[MAX_E], v[MAX_E], w[MAX_E];


void bellman_ford() {
	for (int i = 0; i < n; i++) d[i] = INF;
	d[0] = 0;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < T; i++) {
			int x = u[i], y = v[i];
			if (d[x] < INF) d[y] = min(d[y], d[x]+w[i]); 
			if (d[y] < INF) d[x] = min(d[x], d[y]+w[i]);
		}
	}
}

int main()
{
	while (scanf("%d%d", &T, &n) == 2) {
		for (int i = 0; i < T; i++) {
			scanf("%d%d%d", &u[i], &v[i], &w[i]); 
			u[i]--;
			v[i]--;
		}
		bellman_ford();
		printf("%d\n",d[n-1]);  
	}
	return 0;
}
