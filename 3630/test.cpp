#include <cstdio>
#include <cstring>

struct Trie{
	Trie *next[10];
	int count;
//	Trie(){
//		memset(next, 0, sizeof(Trie*) * 10);
//		count = 0;
//	}
//	~Trie(){
//		for(char a = 0; a <= 9; ++a){
//			if(this->next[a] != NULL){
//				delete this->next[a];
//				this->next[a] = NULL;
//			}
//		}
//	}
};
Trie *root = NULL;
Trie memory[600050];
int Cnt;

bool add(char *str){
	Trie *temp = root;
	for(; *str; ++str){
		if(!temp->next[*str - '0']){
			temp->next[*str - '0'] = &memory[Cnt++];//new Trie();
		}
		if(temp->count){
			temp->count++;
			return false;
		}
		temp = temp->next[*str - '0'];
	}
	temp->count++;
	for(char a = 0; a <= 9; ++a){
		if(temp->next[a]){
			temp->count++;
			return false;
		}
	}
	return true;
}
/*
bool find2(Trie *bar){
	if(bar->count > 1){
		return false;
	}
	for(char a = 0; a <= 9; ++a){
		if(bar->next[a]){
			if(!find2(bar->next[a])){
				return false;
			}
		}
	}
	return true;
}*/

int main(){
	int t, n;
	char phone[20];
	scanf("%d", &t);
	while(t--){
//		delete root;
		Cnt = 0;
		memset(memory, 0, sizeof(memory));
		root = &memory[Cnt++];//new Trie();
		scanf("%d", &n);
		bool flag = true;
		for(int i = 0; i < n; ++i){
			scanf("%s", phone);
			if(flag){
				flag = add(phone);
			}
		}
		printf(flag ? "YES\n" : "NO\n");
	}
}
