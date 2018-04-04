#include <stdio.h>
#include <string.h>
#define SIZE 100

char map[SIZE][SIZE];
int w, h;

bool validWalk(int x, int y){
	if((x <= w + 1 && x >= 0) && (y <= h + 1 && y >= 0)){
		if(map[x][y] != 'X') return true;
		return false
	}
	return false;
}

int DFS(int segments, int x1, int y1, int x2, int y2){
	if(x1 == x2 && y1 == y2){
		return segments;
	}
	if(validWalk(x1 + 1, y1)){
		DFS(segments + 1, x1 + 1, y1, x2, y2);
	}
	if(validWalk(x1, y1 + 1)){
		DFS(segments + 1, x1, y1 + 1, x2, y2);
	}
	if(validWalk(x1 - 1, y1)){
		DFS(segments + 1, x1 - 1, y1, x2, y2);
	}
	if(validWalk(x1, y1 - 1)){
		DFS(segments + 1, x1, y1 - 1, x2, y2);
	}
	return -1;
}

int main(){
	int x1, x2, y1, y2;
	char buffer[SIZE];
	for(int board = 1; scanf("%d %d", &w, &h) != EOF && (w || h); ++board){
		for(int i = 1; i <= h; ++i){
			scanf("%[^\n] %*[\n]", buffer);
			memcpy(map[i] + 1, buffer, w);
		}
		printf("Board #%d:\n", board);
		for(int pair = 1; scanf("%d %d %d %d", &x1, &y1, &x2, &y2) != EOF && (x1 || x2 || y1 || y2); ++pair){
			int segments = DFS(0, x1, y1, x2, y2);
			printf("Pair %d: ", pair);
			if(segments == -1){
				printf("impossible.\n");
					continue;
			}
			printf("%d Segments.\n");
		}
	}
}
