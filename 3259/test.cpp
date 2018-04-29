#include <iostream>
#define SIZE 3000
#define INF 0x7fffffff
#define MIN(a, b) (a < b ? a : b)
using namespace std;

int F;
int N, M, W;
int S, E, T;
int dis[SIZE];
int w[SIZE];
int u[SIZE], v[SIZE];


bool bellmanFord(int source = u[0]){
	for(int i = 0; i < M + W; ++i){
		dis[i] = INF;
	}
	dis[source] = 0;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M + W; ++j){
			int a = u[j], b = v[j];
			if(dis[a] != INF)	dis[b] = MIN(dis[a] + w[j], dis[b]);
			if(dis[b] != INF && w[j] > 0)	dis[a] = MIN(dis[b] + w[j], dis[a]);
		}
	}

	for(int i = 0; i < M + W; ++i){
		int a = u[i], b = v[i];
		if(dis[a] + w[i] < dis[b])	return true;
	}
	return false;
}

int main(){
	cin >> F;
	while(F--){
		cin >> N >> M >> W;
		for(int i = 0; i < M; ++i){
			cin >> u[i] >> v[i] >> w[i];
		}
		for(int i = M; i < M + W; ++i){
			cin >> u[i] >> v[i] >> w[i];
			w[i] *= -1;
		}
		cout << (bellmanFord() ? "YES" : "NO") << endl;
	}
}
