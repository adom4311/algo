/*#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int shark_cnt;
vector <vector<int>> shark;

int mian(void) {
	scanf("%d %d %d", &N, &M, &shark_cnt);
	for (int i = 0; i < shark_cnt; i++) {
		vector <int> tmp(5);
		//scanf("%d %d %d %d %d", &tmp[0], &tmp[1], &tmp[2], &tmp[3], tmp[4]);
		shark.push_back(tmp);
	}

	printf("%d %d %d %d %d", shark[0][0], shark[1][1], shark[2][2], shark[3][3], shark[4][4]);

	return 0;
}*/