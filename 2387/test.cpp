#include <iostream>
#include <cstdio>
#define SIZE 3000
#define INF 0x7fffffff
#define MIN(a, b) (a < b ? a : b)
using namespace std;

int T, N;
int w[SIZE];
int a[SIZE];
int b[SIZE];
int d[SIZE];

void bellmanFord(int source){
	for(int i = 1; i <= N; ++i){
		d[i] = INF;
	}

	d[source] = 0;

	for(int i = 0; i < N - 1; ++i){
		for(int j = 0; j < T; ++j){
			int tempA, tempB;
			tempA = a[j];
			tempB = b[j];
			if(d[tempA] < INF)	d[tempB] = MIN(d[tempB], d[tempA] + w[j]);
			if(d[tempB] < INF)	d[tempA] = MIN(d[tempA], d[tempB] + w[j]);
		}
	}
}

int main(){
	while(cin >> T >> N){
		for(int i = 1; i <= N; ++i){
			w[i] = INF;
		}
		for(int i = 0; i < T; ++i){
			cin >> a[i] >> b[i];
			cin >> w[i];
//			cerr << "a, b, w = " << a[i] << "," << b[i] << "," << w[i] << endl;
		}

		bellmanFord(1);

		cout << d[N] << endl;
	}
}
