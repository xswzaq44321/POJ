#include <iostream>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
using namespace std;

char map[SIZE][SIZE];
char walked[SIZE][SIZE];
int w, h, recSegments;

bool validWalk(int x, int y, int x2, int y2){
	if((x <= w + 1 && x >= 0) && (y <= h + 1 && y >= 0)){
		if(map[y][x] != 'X' && !walked[y][x]){
			walked[y][x] = 1;
			return true;
		}
		if((x == x2 && y == y2)){
			return true;
		}
		return false;
	}
	return false;
}

int DFS(int segments, int x1, int y1, int x2, int y2){
	if(x1 == x2 && y1 == y2){
		if(recSegments > segments || recSegments == -1){
			recSegments = segments;
		}
	}
	if(validWalk(x1 + 1, y1, x2, y2)){
		DFS(segments + 1, x1 + 1, y1, x2, y2);
	}
	if(validWalk(x1, y1 + 1, x2, y2)){
		DFS(segments + 1, x1, y1 + 1, x2, y2);
	}
	if(validWalk(x1 - 1, y1, x2, y2)){
		DFS(segments + 1, x1 - 1, y1, x2, y2);
	}
	if(validWalk(x1, y1 - 1, x2, y2)){
		DFS(segments + 1, x1, y1 - 1, x2, y2);
	}
}

int main(){
	int x1, x2, y1, y2;
	char buffer[SIZE];
	memset(map, ' ', SIZE * SIZE);
	for(int board = 1;scanf("%d %d", &w, &h) != EOF && (w || h); ++board){
		fprintf(stderr, "w, h = %d, %d\n", w, h);
		for(int i = 1; i <= h; ++i){
			scanf("%*[\n]%[^\n]", buffer);
			fprintf(stderr, "buffer = [%s]\n", buffer);
			memcpy(&map[i][0] + 1, buffer, w);
		}

		//testing print
		for(int i = 0; i <= h + 1; ++i){
			for(int j = 0; j <= w + 1; ++j){
				fprintf(stderr, "%c", map[i][j]);
			}
			fprintf(stderr, "\n");
		}
		//testing print over

		printf("Board #%d:\n", board);
		for(int pair = 1; scanf(" %d %d %d %d", &x1, &y1, &x2, &y2) != EOF && (x1 || x2 || y1 || y2); ++pair){
			// reset for next round
			memset(walked, 0, SIZE * SIZE);
			recSegments = -1;

			DFS(0, x1, y1, x2, y2);
			printf("Pair %d: ", pair);
			if(recSegments == -1){
				printf("impossible.\n");
					continue;
			}
			printf("%d Segments.\n", recSegments - 1);
		}
	}
}
