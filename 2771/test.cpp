#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#define SIZE 600

int llink[SIZE], rlink[SIZE]; // no touching
bool used[SIZE]; // no touching
std::vector<int> edge[SIZE]; // begin at 1

// Augumenting Path
bool DFS(int now){
	int next;

	// Try all vetices on the right side
	for(int i = 0; i < (int)edge[now].size(); ++i){
		next = edge[now][i];

		// Visit once only
		if(!used[next]){
			used[next] = true;

			// Unmatched vertex, or augumenting path found
			if(!rlink[next] || DFS(rlink[next])){
				// Update matching
				llink[now] = next;
				rlink[next] = now;
				return true;
			}
		}
	}

	// No augumenting path is found
	return false;
}

// Maximum Bipatite Matching
int Bipartite(int nL, int nR){
	int ans = 0;

	// Numbering from 1 to nL/nR
	memset(llink, 0, (nL + 1)*sizeof(int));
	memset(rlink, 0, (nR + 1)*sizeof(int));

	// Try all vertices on the left side
	for(int i = 1; i <= nL; ++i){
		// Visit once only
		memset(used, false, (nR + 1)*sizeof(bool));
		if(DFS(i)) ++ans;
	}
	return ans;
}

class Student{
	public:
		Student(){
		}
		Student(int hei, char gen, char mus[110], char spo[110]):
			height(hei),
			gender(gen)
		{
			strcpy(music, mus);
			strcpy(sport, spo);
		}
		Student &operator=(const Student &old){
			height = old.height;
			gender = old.gender;
			strcpy(music, old.music);
			strcpy(sport, old.sport);
			return *this;
		}
	int height;
	char gender;
	char music[110];
	char sport[110];
}boy[SIZE], girl[SIZE];

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int N;
		int boyCount = 0, girlCount = 0;
		scanf("%d", &N);
		for(int i = 0; i < N; ++i){
			int hei;
			char gen;
			char mus[110];
			char spo[110];
			scanf("%d %c %s %s", &hei, &gen, mus, spo);
			if(gen == 'M'){
				boy[boyCount++] = Student(hei, gen, mus, spo);
			}else{
				girl[girlCount++] = Student(hei, gen, mus, spo);
			}
		}
		for(int i = 0; i < boyCount; ++i){
			for(int j = 0; j < girlCount; ++j){
				bool match = true;
				Student &lp = boy[i], &rp = girl[j];
				if(abs(lp.height - rp.height) > 40 || strcmp(lp.music, rp.music) || !strcmp(lp.sport, rp.sport)){
					match = false;
				}
				if(match){
					edge[1 + i].push_back(1 + j);
				}
			}
		}

		printf("%d\n", N - Bipartite(N, N));

		for(int i = 0; i <= N; ++i){
			edge[i].clear();
		}
	}
	return 0;
}
