#include <cstdio>
#define SIZE 1000010
#define PRIME_MOD 1073676287

typedef long long int lli;
char s[SIZE];
lli h[SIZE], hBase[SIZE];
char s2[SIZE];
lli h2[SIZE], hBase2[SIZE];
void hashInit(char *s, lli *h, lli *hBase, int len, lli prime = 0xdefaced){
	hBase[0] = 1;
	for(int i = 1; i <= len; ++i){
		h[i] = (h[i - 1] * prime + s[i - 1]) % PRIME_MOD;
		hBase[i] = (hBase[i - 1] * prime) % PRIME_MOD;
	}
}

lli getHash(lli *h, lli *hBase, int a, int b){
	return (h[b + 1] - (h[a] * hBase[b - a + 1]) % PRIME_MOD + PRIME_MOD) % PRIME_MOD;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int count = 0;
		scanf("%s", s2);
		scanf("%s", s);
		int len = 0, len2 = 0;
		for(; s[len]; ++len);
		for(; s2[len2]; ++len2);
		hashInit(s, h, hBase, len);
		hashInit(s2, h2, hBase2, len2);
		for(int i = 0; i <= len - len2; ++i){
			if(getHash(h, hBase, i, i + len2 - 1) == getHash(h2, hBase2, 0, len2 - 1)){
				++count;
			}
		}
		printf("%d\n", count);
	}
}
