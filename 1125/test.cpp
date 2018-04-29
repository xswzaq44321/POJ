#include <iostream>
#define INF 0x7fffffff
#define SIZE 110

using namespace std;

int N;
int dis[SIZE][SIZE];

void floyd(){
	for(int i = 1; i <= N; ++i){
		dis[i][i] = 0;
	}

	for(int k = 1; k <= N; ++k){
		for(int i = 1; i <= N; ++i){
			for(int j = 1; j <= N; ++j){
				if(dis[i][k] != INF && dis[k][j] != INF){
					if(dis[i][k] + dis[k][j] < dis[i][j]){
						dis[i][j] = dis[i][k] + dis[k][j];
					}
				}
			}
		}
	}
}

int main(){
	while(1){
		int min = INF, who = 0;
		for(int i = 0; i < SIZE; ++i){
			for(int j = 0; j < SIZE; ++j){
				dis[i][j] = INF;
			}
		}

		cin >> N;
		if(N == 0)	break;
		for(int i = 1; i <= N; ++i){
			int j;
			cin >> j;
			while(j--){
				int a;
				cin >> a;
				cin >> dis[i][a];
			}
		}

		floyd();
		for(int i = 1; i <= N; ++i){
			int inMax = 0;
			for(int j = 1; j <= N; ++j){
				if(dis[i][j] > inMax){
					inMax = dis[i][j];
				}
			}
			if(inMax < min){
				min = inMax;
				who = i;
			}
		}

		cout << who << " " << min << endl;
	}
}
