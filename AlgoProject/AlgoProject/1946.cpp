/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int T;
int N;

vector<pair<int, int>> a;

int doAlgo() {

	int cnt=0;
	memset(&a, 0x00, sizeof(a));
	scanf("%d", &N);
	a.resize(N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
	}

	sort(a.begin(), a.end());

	int bestrank = a[0].second;
	for (int i= 1; i < N; i++) {
		if (a[i].second < bestrank) {
			bestrank = a[i].second;
			cnt++;
		}else{
			
		}
		
	}


	return cnt;
}

int main(void) {

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		printf("%d\n",doAlgo()+1);
	}
}
*/